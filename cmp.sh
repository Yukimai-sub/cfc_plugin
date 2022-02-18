#!/bin/bash

RVCC=/opt/riscv/bin/riscv64-unknown-elf-g++
TRVCC=../rvi/bin/riscv64-unknown-elf-g++

for fsrc in test/*.cpp
do
	echo "Running test ${fsrc%.cpp}"
	$RVCC -fplugin=./cfc.so -S $fsrc -o "${fsrc%.cpp}.test.S"
	$TRVCC -fcfc -S $fsrc -o "${fsrc%.cpp}.1.test.S"
	diff "${fsrc%.cpp}.test.S" "${fsrc%.cpp}.1.test.S"
done
