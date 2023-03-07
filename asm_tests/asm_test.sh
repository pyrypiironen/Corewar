#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'
TIME='0.1'
#
## $1 should be a flag, $2 should be a directory containing .s files.
## -l checks for leaks, -c checks to compare the bytecode, -a does both.
#
cd .. && make asm && cd asm_tests
if [ "$1" != "" ]; then
	if [ "$1" == "-c" ] || [ "$1" == "-a" ]; then
		if test -d "$2"; then
			find "$2" -name "*.s" -type f -exec bash compare_file.sh {} \;
		else
			printf "usage: bash %s [-l|-c|-a] <directory containing .s files>\n" "$0"
			exit 1
		fi
	fi
	if [ "$1" == "-l" ] || [ "$1" == "-a" ]; then
		if test -d "$2"; then
			find "$2" -name "*.s" -type f -exec bash leaks_test.sh {} \;
		else
			printf "usage: bash %s [-l|-c|-a] <directory containing .s files>\n" "$0"
			exit 1
		fi
	fi
	if [ "$1" != "-a" ] && [ "$1" != "-l" ] && [ "$1" != "-c" ]; then
		printf "usage: bash %s [-l|-c|-a] <directory containing .s files>\n" "$0"
	fi
else
	printf "usage: bash %s [-l|-c|-a] <directory containing .s files>\n" "$0"
	exit 1
fi
