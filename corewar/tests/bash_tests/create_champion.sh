#!/bin/bash

MY_ASM="./my_asm"
HIS_ASM="./sub_asm"
CHAMPION_S="./test_*.s"
CHAMPION_COR="./test_*.cor"
CHAMPION_HEX="./test_*.txt"
MINE="./tmp/mine"
HIS="./tmp/his"
DIFF="./tmp/diff"

if [ ! -d "my_cor" ]; then
    mkdir my_cor
fi
if [ ! -d "my_cor" ]; then
    mkdir my_cor/hexdump
fi
if [ ! -d "my_cor" ]; then
    mkdir his_cor
fi
if [ ! -d "my_cor" ]; then
    mkdir his_cor/hexdump
fi
if [ ! -d "my_cor" ]; then
    mkdir diff
fi


for filename in ./test_*.s; do
    $MY_ASM $filename
done

mv *.cor my_cor

for filename in ./test_*.s; do
    $HIS_ASM $filename
done

mv *.cor his_cor

for filename in ./my_cor/test_*.cor; do
    tmp=${filename##*/}
    hexdump -C $filename > ./my_cor/hexdump/${tmp%.*}.txt
done

for filename in ./his_cor/test_*.cor; do
    tmp=${filename##*/}
    hexdump -C $filename > ./his_cor/hexdump/${tmp%.*}.txt
done

for filename in ./his_cor/hexdump/*.txt; do
    tmp=${filename##*/}
    diff his_cor/hexdump/$tmp my_cor/hexdump/$tmp > ./diff/diff_$tmp
    FILESIZE=$(stat -c%s ./diff/diff_$tmp)
    if (( $FILESIZE > 0 ))
    then
        echo -e "\e[91m"
        echo "FILES $filename and ./my_cor/hexdump/$tmp differes"
        echo -e "\e[0m"
        cat -e ./diff/diff_$tmp
    else
        echo -e "\e[92m File ${tmp%.*}.cor is OK \e[0m"
    fi
done