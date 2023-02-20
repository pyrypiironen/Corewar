#!/bin/bash

#ASM=$(./asm_orig)

if test -d orig_testfiles; then
	echo "Directory already exists"
else
	mkdir orig_testfiles
fi

for file in ./asm_checks/*
do
	./asm_orig $file
done
mv ./asm_checks/*.cor orig_testfiles

for file in ./asm_errors/*
do
	./asm_orig $file
done
mv ./asm_errors/*.cor orig_testfiles

for file in ./champs/*
do
	./asm_orig $file
done
mv ./champs/*.cor orig_testfiles