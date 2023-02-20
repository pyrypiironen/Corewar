#!/bin/bash

ASM=$(./asm_orig)

if test -d orig_testfiles; then
	echo "Directory already exists"
else
	mkdir orig_testfiles
fi

for file in ./asm_checks/*
do
	./asm $file
done
mv ./asm_checks/*.cor orig_testfiles

for file in ./asm_errors/*
do
	./asm $file
done
mv ./asm_errors/*.cor orig_testfiles

for file in ./champs/*
do
	./asm $file
done
mv ./champs/*.cor orig_testfiles