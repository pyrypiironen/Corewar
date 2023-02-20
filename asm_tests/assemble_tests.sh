#!/bin/bash

#ASM=$(./asm_orig)

if test -d my_testfiles; then
	echo "Directory already exists"
else
	mkdir my_testfiles
fi

for file in ./asm_checks/*
do
	./asm $file
done
mv ./asm_checks/*.cor my_testfiles

for file in ./asm_errors/*
do
	./asm $file
done
mv ./asm_errors/*.cor my_testfiles

for file in ./champs/*
do
	./asm $file
done
mv ./champs/*.cor my_testfiles