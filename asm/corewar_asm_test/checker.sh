#!/bin/bash
echo "Directory of your asm file"
read path
if test -f "$path/asm"; then
    echo "${path}asm found"
else
    echo "${path}asm not found"
    exit 1
fi
for i in invalid_asm/*
do
    ./$path/asm $i > $i.out.own
done
mv invalid_asm/*.out.own invalid_asm_out/
for j in invalid_asm_out/*.out
do
    if cmp -s $j $j.own; then
        printf "$j %40s\n" Same
    else
        printf "$j %40s\n" Differ
    fi
done
rm invalid_asm_out/*.out.own
for i in valid_asm/*.s
do
    ./$path/asm $i
done
for k in valid_asm/*.cor
do
    if cmp -s $k $k.orig; then
        printf "$k %20s\n" Same
    else
        printf "$k %20s\n" Differ
    fi
done
rm .cor
printf "\nTests that will differ because of path printing:\n42.invalid\nsyntax_error_05.s\n"