# rm corewar
# cd ..
# make vm
# make vm_clean
# cp corewar ./vm_tests/corewar
# cd vm_tests



champs=' ./champs/Car.cor ./champs/Gagnant.cor'

corewar='./corewar'"$champs"' -d '
corewar42='./corewar42'"$champs"' -d '
cycle=0

while [ $cycle -lt 12 ]
do
	$corewar $cycle > corewar.txt
	$corewar $cycle > corewar42.txt
	((cycle++))
	diff corewar.txt corewar42.txt
	if [ diff != "" ]; then
		echo "Difference at cycle " $cycle
	else
		echo "OK at cycle " $cycle
	fi

	
done




