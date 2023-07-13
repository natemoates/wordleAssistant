# Nathaniel Oates
# CPSC 1070 : Section 010
# Project 4 : Wordle Assistant!
# December 5, 2022

# compiles all header and source code files in Project-4.out
# and prints any compilation errors, warnings, and notes to
# the terminal
compile:
	gcc Wordle.h Wordle.c Project-4.c -o Project-4.out -Wall

# runs Project-4.out
run:
	./Project-4.out

# removes all files ending in .out
clean:
	rm *.out
