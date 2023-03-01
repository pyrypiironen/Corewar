make vm
make vm_clean

# fork, ld, live, zjmp, sti
./corewar -dump 3000 source_champs/champs/Car.cor source_champs/champs/Gagnant.cor > txt_project.txt

./core_orig -d 1500 source_champs/champs/Car.cor source_champs/champs/Gagnant.cor > txt_orig.txt

./hmarone_core -v 2 -dump 3000 source_champs/champs/Car.cor source_champs/champs/Gagnant.cor > txt_hmarone.txt