#!/usr/bin/env python3

import os
import subprocess
import sys
from colorama import Fore, Back, Style

championsDir = 'champs/'
all_champs = os.listdir(championsDir)

dump_index = sys.argv.index("-dump") if "-dump" in sys.argv else 0
dump = False if not dump_index else "100"

if dump_index > 0:
    try:
        dump = str(sys.argv[dump_index + 1])
    except:
        print("You must give a number after dump flag")
        exit()

print(Fore.BLUE + "Now testing corewar leaks with 4 champions and dump at " + str(dump) + " (dump is not checked)")
n = 1
while (n < len(all_champs) - 4):
    if dump:
        print(Style.RESET_ALL + "With players: " + all_champs[n] + ", " + all_champs[n+1] + ", " + all_champs[n+2] + ", " + all_champs[n+3])
        our_leaks = subprocess.run(
            ["leaks", "--atExit", "--", "../corewar", "-dump", dump, "-t", ''
            .join(championsDir) + all_champs[n], ''.join(championsDir) + all_champs[n+1], ''
            .join(championsDir) + all_champs[n+2], ''.join(championsDir) + all_champs[n+3]],
            text=True, capture_output=True, encoding="ISO-8859-1").stdout
    else:
        print(Style.RESET_ALL + "With players: " + all_champs[n] + ", " + all_champs[n+1] + ", " + all_champs[n+2] + ", " + all_champs[n+3])
        our_leaks = subprocess.run(
            ["leaks", "--atExit", "--", "../corewar", "-t", ''
            .join(championsDir) + all_champs[n], ''.join(championsDir) + all_champs[n+1], ''
            .join(championsDir) + all_champs[n+2], ''.join(championsDir) + all_champs[n+3]],
            text=True, capture_output=True, encoding="ISO-8859-1").stdout
    print (Back.RED + "Leaks found" + Style.RESET_ALL) if "LEAK" in our_leaks else print(Back.GREEN + "No leaks found" + Style.RESET_ALL)
    n += 4
