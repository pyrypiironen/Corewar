#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'
TIME='0.1'

ASM="../asm"

if [ "$1" != "" ]; then
	if test -f $1; then
		leaks --atExit -- $ASM $1 > tmp.txt
		OUTPUT=$(grep "leaked bytes" tmp.txt | cut -d ' ' -f 6)
		#echo "$OUTPUT"
		let OUTINT=$OUTPUT
		if [ $OUTINT != 0 ]; then
			printf "$RED Your assembler may be leaking memory$NC ("$1")\n"
		fi
		/bin/rm tmp.txt
	fi
	else
		printf "usage: bash %s <file_to_assemble.s>\n" "$0"
fi