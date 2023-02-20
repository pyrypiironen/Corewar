##!/bin/bash


if test -f origout.txt; then
	rm origout.txt
fi
if test -f newout.txt; then
	rm newout.txt
fi

for file in ./orig_testfiles/*
do
	NEWFILE=$(echo \"$file\" | sed 's/orig_/my_/g' | sed 's/"//g')
	#echo "$file"
	echo "$NEWFILE"
	hexdump -C $file > org_hex.txt
	hexdump -C $NEWFILE > new_hex.txt
	diff -u org_hex.txt new_hex.txt
	#hexdump -C $file >> origout.txt
done
rm org_hex.txt new_hex.txt
#
#for file in ./my_testfiles/*
#do
#	hexdump -C $file >> newout.txt
#done
#
#diff -u origout.txt newout.txt
