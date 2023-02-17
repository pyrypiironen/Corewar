#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'
TIME='0.2'


if test -f tmp1.cor; then
	rm tmp1.cor
fi
if test -f tmp2.cor; then
	rm tmp2.cor
fi

cd .. && make && cd asm_tests

cp $1 tmp1.s
cp $1 tmp2.s
OUT_ORG=$(./asm_orig tmp1.s)
OUT_NEW=$(../asm tmp2.s)
declare -i ERROR=1
if test -f tmp1.cor; then
	if test -f tmp2.cor; then
		printf "$GREEN both assemblers writing code.$NC\n"
		ERROR=0
	else
		printf "$RED ERROR: original asm wrote to file when yours did not.$NC\n"
		printf "$YELLOW Your output:\n$NC $OUT_NEW"
		exit 1
	fi
fi
DIFF=$(diff -u tmp1.cor tmp2.cor)
#echo -e "ERROR$ERROR"
if [ $ERROR == 1 ]; then
	printf "$YELLOW Original:\n$NC $OUT_ORG\n"
	printf "$YELLOW Your asm:\n$NC $OUT_NEW\n"
	exit 1
fi
if test $DIFF; then
	printf "$RED ERROR: bytecode did not match.$NC\n"
fi
rm tmp1.s tmp2.s
#./asm_orig champs/Car.s champs/barriere.s champs/Gagnant.s
#./corewar_orig -n champs/Gagnant.cor champs/Car.cor
