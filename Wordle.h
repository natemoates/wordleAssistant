/*  Nathaniel Oates
    CPSC 1070 : Section 010
    Project 4 : Wordle Assistant!
    December 5, 2022
 */

/*  This is the header file for the Wordle Assistant. This file prototypes
    all the functions defined in the Wordle.c file. */

#ifndef WORDLE_H
#define WORDLE_H

#include <stdio.h>

int loadDictionary(char *[]);

char * promptUser(void);

void processGuess(char *[], int num5, char, char, char, char, char);

void printResults(char *[], int);

void helpMe(void);

#endif
