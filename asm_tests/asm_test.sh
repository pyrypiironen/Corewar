#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
NC='\033[0m'
TIME='0.1'


cd .. && make asm && cd asm_tests
if [ "$1" != "" ]; then
	if test -d "$1"; then
		find "$1" -name "*.s" -type f -exec bash compare_file.sh {} \;
	else
		printf "usage: bash %s <directory containing .s files>\n" "$0"
	fi
else
	printf "usage: bash %s <directory containing .s files>\n" "$0"
fi
