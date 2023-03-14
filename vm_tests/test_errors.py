import os
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

# Do you want to print the error messages
print_msg = True


# Make and copy new corewar to this folder.
#os.system('cd .. && make && make clean && cp corewar ./vm_tests/corewar && cd vm_tests')

print(yellow('Testing invalid champions'))

print((blue('Invalid header: ')), end='')
result = subprocess.run(['./corewar', 'error_champs/invalid_header.cor'], capture_output=True)
if result.returncode != 0 and "ERROR:" in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('Empty file: ')), end='')
result = subprocess.run(['./corewar', 'error_champs/no_code.cor'], capture_output=True)
if result.returncode != 0 and "ERROR:" in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('Code too big: ')), end='')
result = subprocess.run(['./corewar', 'error_champs/too_big.cor'], capture_output=True)
if result.returncode != 0 and "ERROR:" in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('Non-existent champion: ')), end='')
result = subprocess.run(['./corewar', 'error_champs/casper.cor'], capture_output=True)
if result.returncode != 0 and "ERROR:" in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print('')

print(yellow('Testing invalid input'))
print((blue('Champ without .cor: ')), end='')
result = subprocess.run(['./corewar', 'champs/Gagnant'], capture_output=True)
if result.returncode != 0 and "Wrong usage." in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('Negative dump flag: ')), end='')
result = subprocess.run(['./corewar', 'champs/Gagnant.cor', '-dump', '-42', 'champs/turtle.cor'], capture_output=True)
if result.returncode != 0 and "Wrong usage." in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('-dump flag without argument: ')), end='')
result = subprocess.run(['./corewar', '-dump', 'champs/Gagnant.cor', 'champs/turtle.cor'], capture_output=True)
if result.returncode != 0 and "Wrong usage." in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('Two -dump flags: ')), end='')
result = subprocess.run(['./corewar', '-dump', '21', 'champs/Gagnant.cor', '-dump', '42', 'champs/turtle.cor'], capture_output=True)
if result.returncode != 0 and "Wrong usage." in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('Same -n flag: ')), end='')
result = subprocess.run(['./corewar', '-n', '1', 'champs/Gagnant.cor', '-n', '1', 'champs/turtle.cor'], capture_output=True)
if result.returncode != 0 and "Wrong usage." in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('-n flag too big: ')), end='')
result = subprocess.run(['./corewar', 'champs/Gagnant.cor', '-n', '5', 'champs/turtle.cor'], capture_output=True)
if result.returncode != 0 and "Wrong usage." in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('-n flag without argument: ')), end='')
result = subprocess.run(['./corewar', '-n', 'champs/Gagnant.cor', 'champs/turtle.cor'], capture_output=True)
if result.returncode != 0 and "Wrong usage." in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))

print((blue('-n flag at the end: ')), end='')
result = subprocess.run(['./corewar', 'champs/Gagnant.cor', 'champs/turtle.cor', '-n', '2'], capture_output=True)
if result.returncode != 0 and "Wrong usage." in result.stderr.decode('utf-8'):
	print(green('OK'))
	if print_msg:
		print(red(result.stderr.decode('utf-8')))
else:
	print(red('KO'))





