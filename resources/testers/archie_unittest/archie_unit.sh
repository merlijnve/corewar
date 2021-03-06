#!/bin/bash
PATH_YOUR_CW="../../../srcs/vm/corewar"
# PATH_YOUR_CW="../../../resources/nstabel/corewar"
PATH_PLAYERS="../valid_asm/valid_cor/*.cor"

# players=("vm_test")
#( ( i <= $CYCLES ) && ( $error == 0 ) )
if [ -z "$1"]
    then
        CYCLES=10000
    else
    CYCLES=$1
fi

OS=$(uname -s)
if [ $OS == Linux ]
    then
        PATH_ORGN_CW="cor_bin/lin/corewar"
else
    PATH_ORGN_CW="cor_bin/mac/corewar"
fi

function    test_players()
{
    # CYCLES=10000

    rm ./diff/*
    for player in $PATH_PLAYERS
    do
        (
            error=0
            # echo $player
            for (( i=1; ( ( i <= $CYCLES ) && ( $error == 0 ) ) ; i+=100))
            do
                $PATH_ORGN_CW $player -d $i > diff/$(basename $player)_"$i"_og.dump
                $PATH_YOUR_CW $player -d $i > diff/$(basename $player)_"$i"_ours.dump
                if ! cmp -s diff/$(basename $player)_"$i"_og.dump diff/$(basename $player)_"$i"_ours.dump; then
                    printf '\033[0m[%10s] ' "$player"
                    ((i=i-1))
                    printf "\033[0;31mmemory is NOT the same at cycle [%d]\n\033[0m" "$i" ;
                    ((error=1))
                else
                    rm ./diff/$(basename $player)_"$i"_*.dump
                fi
            done
            if [ $error == 0 ] ; then
                printf '\033[0m[%10s] ' "$player"
                ((i=i-1))
                printf '\033[0;32mPerfect! Memory is the same at all cycles until %s\n\033[0m' "$i"
            fi
        ) &
    done
}

if [ "$1" == "-help" ] ; then
    echo "usage: sh vm_tester.sh <filename1.cor> <filename2.cor> <cycles>"
    exit 1
elif [ $# -lt 2 ] ; then
    test_players
    exit 1
fi

CYCLES=${@: -1}
n=$(($# - 1))
for arg do
    [ "$n" -gt 0 ] && set -- "$@" "$arg"
    shift
    n=$((n - 1))
done
for arg do
    if [ ! -f $arg ]; then
        echo "error: file $arg does not exist" ; exit 1
    fi
done
re='^[0-9]+$'
if ! [[ $CYCLES =~ $re ]]; then
    echo "error: $CYCLES is not a number" >&2 ; exit 1
fi
for (( i=1; i <= $CYCLES; i+=10))
do
    $PATH_ORGN_CW $@ -d $i > diff/origin_output1
    $PATH_YOUR_CW $@ -d $i > diff/yours_output2
    if ! cmp -s "diff/origin_output1" "diff/yours_output2"; then
        printf "\033[0;31mmemory is NOT the same at cycle [%d]\n\033[0m" "$i" ; exit 1
    fi
done
    printf '\033[0;32mperfect! memory is the same at all cycles until %s\n\033[0m' "$CYCLES"

