#!/bin/bash

TEST_NAME="zjmp"

MY_ASM="./my_asm"
HIS_ASM="./sub_asm"
CHAMPION_S="./test_$TEST_NAME.s"
CHAMPION_COR="./test_$TEST_NAME.cor"
CHAMPION_HEX="./test_$TEST_NAME.txt"
MINE="./tmp/mine"
HIS="./tmp/his"
DIFF="./tmp/diff"

$MY_ASM $CHAMPION_S
hexdump -C $CHAMPION_COR > $MINE
rm -f $CHAMPION_COR
$HIS_ASM $CHAMPION_S
hexdump -C $CHAMPION_COR > $HIS
diff $MINE $HIS > $DIFF

FILESIZE=$(stat -c%s "$DIFF")

if (( $FILESIZE > 0 ))
then
    echo $DIFF
    rm -f $CHAMPION_COR
else
    hexdump -C $CHAMPION_COR > $CHAMPION_HEX
fi

rm -f $MINE
rm -f $HIS
rm -f $DIFF
