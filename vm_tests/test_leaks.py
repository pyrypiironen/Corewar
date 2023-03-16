import os
import subprocess




# Define colors.
def red(text):
    return '\033[31m' + text + '\033[0m'
def green(text):
    return '\033[32m' + text + '\033[0m'
def yellow(text):
    return '\033[33m' + text + '\033[0m'
def blue(text):
    return '\033[34m' + text + '\033[0m'

# Make and copy new corewar to this folder.
os.system('cd .. && make && make clean && cp corewar ./vm_tests/corewar && cd vm_tests')

# Define champs, commands, log files and variables
champsDir = 'champs/'
all_champs = os.listdir(champsDir)
n = len(all_champs)
i = 0
j = 0
corewar = 'leaks --atExit -- ./corewar ' + champsDir + all_champs[i] + ' ' + champsDir + all_champs[j]
print_result = False



while (i < n):
	j = 0
	while (j < n):
		print(blue(all_champs[i] + '   vs   ' + all_champs[j] + ' '), end='')
		result = subprocess.run(corewar.split(), capture_output=True)
		if ('0 leaks for 0 total leaked bytes' in result.stdout.decode('utf-8')):
			print(green('OK'))
			if (print_result):
				print(result.stdout.decode('utf-8'))
		else:
			print(red('KO'))
		j +=1
	i += 1



