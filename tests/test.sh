#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'
TIME='0.2'

rm tmp1.cor tmp2.cor

cd .. && make && cd tests

cp $1 tmp1.s
cp $1 tmp2.s
OUT_ORG=$(./asm_orig tmp1.s)
OUT_NEW=$(../asm tmp2.s)
ERROR=1
if test -f tmp1.cor; then
	if test -f tmp2.cor; then
		echo -e ""$GREEN"both assemblers writing code."$NC""
		ERROR=0
	else
		echo -e ""$RED"ERROR: original asm wrote to file when yours did not."$NC""
		exit 1
	fi
fi
DIFF=$(diff -u tmp1.cor tmp2.cor)
#echo -e "ERROR$ERROR"
#if ERROR; then
if test $DIFF; then
	echo -e ""$RED"ERROR: bytecode did not match."$NC""
fi
rm tmp1.s tmp2.s
#./asm_orig champs/Car.s champs/barriere.s champs/Gagnant.s
#./corewar_orig -n champs/Gagnant.cor champs/Car.cor