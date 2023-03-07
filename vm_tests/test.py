import os
import filecmp
import time
import subprocess
import difflib


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
os.system('rm corewar && cd .. && make vm && make vm_clean && cp corewar ./vm_tests/corewar && cd vm_tests')

# Set the starting cycle of testing.
cycle = 0			#First diff comes in cycle 1105

# Define champs
champs = ' ./champs/Car.cor ./champs/Gagnant.cor'

# Define commands and log files
corewar = './corewar' + champs + ' -d '
corewar42 = './corewar42' + champs + ' -d '
corewar_info = './corewar' + champs + ' -c '
corewar_text = './logs/corewar.txt'
corewar42_text = './logs/corewar42.txt'
info_text = './logs/info.txt'






# Next:
# Write winner texts to corewar.
# Add break point to test loop.


while cycle < 50:
	# Open text files, run the programs and write outputs to text files.
	with open(corewar_text, 'w') as f1:
		subprocess.run(corewar + str(cycle), shell=True, stdout=f1)
	with open(corewar42_text, 'w') as f2:
		subprocess.run(corewar42 + str(cycle), shell=True, stdout=f2)
	# Compare text files.
	with open(corewar_text, 'r') as f1:
		output = f1.read()
	with open(corewar42_text, 'r') as f2:
		output42 = f2.read()
	s = difflib.SequenceMatcher(None, output, output42)
	# Print result.
	if s.ratio() == 1.0:
		print(green('Cycle ' + str(cycle) + ' : OK'))
	else:
		print(red('Cycle ' + str(cycle) + ' : Difference found!'))
		break
	# Iterate cycle for dump.
	cycle += 1


with open(info_text, 'w') as f3:
	subprocess.run(corewar_info + str(cycle), shell=True, stdout=f3)


