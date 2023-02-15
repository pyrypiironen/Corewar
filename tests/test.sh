#!/bin/bash

rm tmp1.cor tmp2.cor

cd .. && make && cd tests

cp $1 tmp1.s
cp $1 tmp2.s
./asm_orig tmp1.s
../asm tmp2.s
diff -u tmp1.cor tmp2.cor
rm tmp1.s tmp2.s
#./asm_orig champs/Car.s champs/barriere.s champs/Gagnant.s
#./corewar_orig -n champs/Gagnant.cor champs/Car.cor