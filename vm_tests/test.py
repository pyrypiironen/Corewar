import os
import filecmp
import time
import subprocess
import difflib


os.system('rm corewar && cd .. && make vm && make vm_clean && cp corewar ./vm_tests/corewar && cd vm_tests')

champs = ' ./champs/Car.cor ./champs/Gagnant.cor'
corewar = './corewar' + champs + ' -d '
corewar42 = './corewar42' + champs + ' -d '
cycle = 0

while cycle < 500:
	#command = corewar + str(cycle) + ' > corewar.txt'
	#command42 = corewar42 + str(cycle) + ' > corewar42.txt'

	with open('corewar.txt', 'w') as f1:
		subprocess.run(corewar + str(cycle), shell=True, stdout=f1)
	with open('corewar42.txt', 'w') as f2:
		subprocess.run(corewar42 + str(cycle), shell=True, stdout=f2)

	with open('corewar.txt', 'r') as f1, open('corewar42.txt', 'r') as f2:
		diff = difflib.unified_diff(f1.readlines(), f2.readlines(), lineterm='')
		for line in diff:
			print(line)

	#are_equal = filecmp.cmp('corewar.txt', 'corewar42.txt')
	#if are_equal:
	#	print('The files are equal')
	#else:
	#	print('The files are different')
	cycle += 1
