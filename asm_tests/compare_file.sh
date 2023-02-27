#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'
TIME='0.1'


if test -f tmp1.cor; then
	rm tmp1.cor
fi
if test -f tmp2.cor; then
	rm tmp2.cor
fi

cp $1 tmp1.s
cp $1 tmp2.s
OUT_ORG=$(./asm_orig tmp1.s 2>&1)
OUT_NEW=$(../asm tmp2.s 2>&1)
declare -i ERROR=1
printf "$1\n"
if test -f tmp1.cor; then
	if test -f tmp2.cor; then
		#printf "$GREEN both assemblers writing code.$NC\n"
		ERROR=0
	else
		printf "$RED ERROR: original asm wrote to file when yours did not.$NC\n"
		printf "$YELLOW Your output:\n$NC $OUT_NEW"
		rm tmp1.s tmp2.s tmp1.cor
		exit 1
	fi
else
	if test -f tmp2.cor; then
	printf "$YELLOW Original asm did not write a .cor file when yours did.$NC\n"
	printf "Output:\n$OUT_ORIG\n"
	rm tmp1.s tmp2.s tmp2.cor
	exit 1
	fi
fi

#echo -e "ERROR$ERROR"
if [ $ERROR == 1 ]; then
	printf "$YELLOW\tOriginal\n$NC\t%s\n" "$OUT_ORG"
	printf "$YELLOW\tYour asm\n$NC\t%s\n" "$OUT_NEW"
	rm tmp1.s tmp2.s
	exit 1
fi
hexdump -C tmp1.cor > org_hex.txt
hexdump -C tmp2.cor > new_hex.txt
DIFF=$(diff -u org_hex.txt new_hex.txt)
if test $DIFF; then
	printf "$RED ERROR: bytecode did not match.$NC\n"
else
	printf "$GREEN\tPassed!\n$NC"
fi
rm tmp1.s tmp2.s tmp1.cor tmp2.cor org_hex.txt new_hex.txt
