#!/bin/bash
echo "Directory of your asm file"
read path
if test -f "$path/asm"; then
    echo "${path}/asm found"
else
    echo "${path}/asm not found"
    exit 1
fi
for i in invalid_asm/*
do
    ./$path/asm $i > $i.out.own
    ./orig_asm $i > $i.out
done
mv invalid_asm/*.out invalid_asm_out/
mv invalid_asm/*.out.own invalid_asm_out/
for j in invalid_asm_out/*.out
do
    if cmp -s $j $j.own; then
        printf "$j %40s\n" Same
    else
        printf "$j %40s\n" Differ
    fi
done

for l in valid_asm/*.s
do
    ./orig_asm $l
done
for p in valid_asm/*.cor
do
    mv $p $p.orig 
done
for t in valid_asm/*.s
do
    ./$path/asm $t
done
mv valid_asm/*.cor valid_asm_out/
mv valid_asm/*.cor.orig valid_asm_out/
for k in valid_asm_out/*.cor
do
    if cmp -s $k $k.orig; then
        printf "$k %20s\n" Same
    else
        printf "$k %20s\n" Differ
    fi
done
rm .cor