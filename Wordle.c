/*  Nathaniel Oates
    CPSC 1070 : Section 010
    Project 4 : Wordle Assistant!
    December 5, 2022
 */


/*  This file contains the source code for all Wordle Assistant functionality.
    This file contains five functions that have the following capabilities:
    loading the five letter words in a UNIX dictionary file into an array of
    pointers to characters within this file; prompting a user to provide their
    current Wordle status for analysis; processing the user's inputted guess
    and altering the Word Bank to contain only viable words for the user's
    current game; printing the viable words in an easy-to-read format; driving
    the use of these other functions so the program works as intended.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Wordle.h"

/*  loads a passed array of character pointers with five letter words from
    /usr/share/dict/words and returns the amount of 5 letter words in bank */
int loadDictionary(char *bank[]){
    
    // declares a pointer to a file and opens the dictionary file
	FILE *file;
	file = fopen("/usr/share/dict/words", "r");
    
	int counter = 0;
	char str[50];
    
    // loops through each word in the file until the file ends
	while(fgets(str, 50, file) != NULL){
		if(strlen(str) == 6){
			if(str[3] != '\''){
                // allocates memory for a temporary char pointer
				char *wordPtr = malloc(sizeof(char));
				strcpy(wordPtr, str);
				bank[counter] = wordPtr;
				counter++;
			}
		}
	}
    
    // closes the dictionary file
    fclose(file);
    
	return counter;
}

/*  prompts the user to input their guess and provides an example formatting
    and returns a pointer to the user's input stripped of blank spaces */
char * promptUser(void){
	char readIn[10];
	char *ptr;

	printf("Enter the Wordle clues using the following scheme: \n");
	printf("         A-Z for a known letter in the right position\n");
	printf("         a-z for a letter that is correct in the wrong position\n");
	printf("         * for unknown letter\n");
	printf("         Separate each with a space (e.g., T * G i R)\n");
	printf("Enter your query now: ");
	scanf("%[^\n]%*c", readIn);
	int i;
	int counter = 0;
    char final[6];
    
    // cycles through the user's input and strips unnecessary spaces
	for(i = 0; i < strlen(readIn); i++){
		if(readIn[i] != ' '){
			char temp = readIn[i];
			final[counter] = temp;
			counter++;
		}
	}
    
    // set ptr to point to final and returns ptr
	ptr = final;
	return ptr;
}

/*  processes the user's inputted guess and strips the Word Bank of non-viable words */
void processGuess(char *wordBank[], int num5, char one, char two, char three, char four, char five){
	int i;
	int counter = 0;
    
    // declares and initializes five int variables that represent boolean
    // values, used to indicate if the char at a certain index is lowercase
	int oneLower = 0;
	int twoLower = 0;
	int threeLower = 0;
	int fourLower = 0;
	int fiveLower = 0;

    // if a char is not an asterisk and is uppercase, then this will loop
    // through each word in wordBank and count the words with that same letter
    // in the same position or index as the user's inputted word
	if(one != '*' && isupper(one) > 0){
		for(i = 0; i < num5; i++){
			if(wordBank[i][0] == one || wordBank[i][0] == tolower(one)){
				counter++;
			}
		}	
		printf("Found %d words starting with %c\n", counter, one);
	}
	counter = 0;
	if(two != '*' && isupper(two) > 0){
        for(i = 0; i < num5; i++){
            if(wordBank[i][1] == two || wordBank[i][1] == tolower(two)){
                counter++;
            }
        }
        printf("Found %d words with %c in position 2\n", counter, two);
	}
	counter = 0;
	if(three != '*' && isupper(three) > 0){
        for(i = 0; i < num5; i++){
            if(wordBank[i][2] == three || wordBank[i][2] == tolower(three)){
                counter++;
            }
        }
        printf("Found %d words with %c in position 3\n", counter, three);
	}
	counter = 0;
	if(four != '*' && isupper(four) > 0){
        for(i = 0; i < num5; i++){
            if(wordBank[i][3] == four || wordBank[i][3] == tolower(four)){
                counter++;
            }
        }
        printf("Found %d words with %c in position 4\n", counter, four);
	}
	counter = 0;
	if(five != '*' && isupper(five) > 0){
        for(i = 0; i < num5; i++){
            if(wordBank[i][4] == five || wordBank[i][4] == tolower(five)){
                    counter++;
            }
        }
        printf("Found %d words with %c in position 5\n", counter, five);
	}

    // for each uppercase letter in the user's inputted word, all words that
    // do not have the same letter at the same position as the user's word are
    // removed from wordBank. For each lowercase letter in the user's word, the
    // integer corresponding to the letter at that index is assigned to 1,
    // indicating the letter at that position is lowercase;
	if(one != '*'){
		if(isupper(one) > 0){
            for(i = 0; i < num5; i++){
                if(wordBank[i][0] != tolower(one)){
                    wordBank[i] = "";
                }
            }
		}
		else{
			oneLower = 1;
		}
    }
	if(two != '*'){
        if(isupper(two) > 0){
            for(i = 0; i < num5; i++){
                if(wordBank[i][1] != tolower(two)){
                    wordBank[i] = "";
                }
            }
        }
        else{
            twoLower = 1;
            }
    }
	if(three != '*'){
        if(isupper(three) > 0){
            for(i = 0; i < num5; i++){
                if(wordBank[i][2] != tolower(three)){
                    wordBank[i] = "";
                }
            }
        }
        else{
            threeLower = 1;
        }
    }
	if(four != '*'){
        if(isupper(four) > 0){
            for(i = 0; i < num5; i++){
                if(wordBank[i][3] != tolower(four)){
                    wordBank[i] = "";
                }
            }
        }
        else{
            fourLower = 1;
        }
    }
	if(five != '*'){
        if(isupper(five) > 0){
            for(i = 0; i < num5; i++){
                if(wordBank[i][4] != tolower(five)){
                    wordBank[i] = "";
                }
            }
        }
        else{
            fiveLower = 1;
        }
    }

    // each integer representing a boolean is checked, and if the integer is 1
    // representing true, all words remaing in the word banked that do not
    // contain, at any index, the letter that corresponds to the boolean being
    // checked will be removed from wordBank.
	if(oneLower == 1){
		int i;
		int j;
		int hasChar = 0;
		for(i = 0; i < num5; i++){
			if(strlen(wordBank[i]) > 0){
				hasChar = 0;
				for(j = 0; j < 5; j++){
					if(wordBank[i][j] == one){
						hasChar = 1;
					}
				}
				if(hasChar == 0){
					wordBank[i] = "";
				}
			}
		}
	}
	if(twoLower == 1){
        int i;
        int j;
        int hasChar = 0;
        for(i = 0; i < num5; i++){
            if(strlen(wordBank[i]) > 0){
                hasChar = 0;
                for(j = 0; j < 5; j++){
                    if(wordBank[i][j] == two){
                        hasChar = 1;
                    }
                }
                if(hasChar == 0){
                    wordBank[i] = "";
                }
            }
        }
    }
	if(threeLower == 1){
        int i;
        int j;
        int hasChar = 0;
        for(i = 0; i < num5; i++){
            if(strlen(wordBank[i]) > 0){
                hasChar = 0;
                for(j = 0; j < 5; j++){
                    if(wordBank[i][j] == three){
                        hasChar = 1;
                    }
                }
                if(hasChar == 0){
                    wordBank[i] = "";
                }
            }
        }
    }
	if(fourLower == 1){
        int i;
        int j;
        int hasChar = 0;
        for(i = 0; i < num5; i++){
            if(strlen(wordBank[i]) > 0){
                hasChar = 0;
                for(j = 0; j < 5; j++){
                    if(wordBank[i][j] == four){
                        hasChar = 1;
                    }
                }
                if(hasChar == 0){
                    wordBank[i] = "";
                }
            }
        }
    }
	if(fiveLower == 1){
        int i;
        int j;
        int hasChar = 0;
        for(i = 0; i < num5; i++){
            if(strlen(wordBank[i]) > 0){
                hasChar = 0;
                for(j = 0; j < 5; j++){
                    if(wordBank[i][j] == five){
                        hasChar = 1;
                    }
                }
                if(hasChar == 0){
                    wordBank[i] = "";
                }
            }
        }
    }
}

/* prints the viable words after processing in an listed format */
void printResults(char *wordBank[], int num){
    if(num != 0){
        printf("Viable Options:\n");
        int i;
        int counter = 0;
        for(i = 0; i < num; i++){
            // filters out empty wordBank values
            if(strlen(wordBank[i]) > 0){
                printf("        %d: %s",counter, wordBank[i]);
                counter++;
            }
        }
        printf("\n");
    }
    else{
        printf("There are too many possibilities!");
    }
}

/* drives the order and proper functionality of the Wordle Assistant */
void helpMe(void){
	char *wordBank[7000];
    int numWords = loadDictionary(wordBank);
    
    printf("\nWelcome to the Wordle Assistant!\n");
    printf("Processing Dictionary\n");
    printf("%d out of 102401 words in the dictionary are 5 characters!\n", numWords);
    printf("\n");
	
	char userInput[6];
    
    // copies the user's guess into the userInput C-style string
	strcpy(userInput,promptUser());
    
    processGuess(wordBank, numWords, userInput[0], userInput[1], userInput[2], userInput[3], userInput[4]);
    
	int i;
	int asteriskCount = 0;
	for(i = 0; i < 5; i++){
		if(userInput[i] == '*'){
			asteriskCount++;
		}
	}
    
    // if only one letter is known, printResults is sent 0 as a signal to not
    // print viable options
	if(asteriskCount < 4){
		printResults(wordBank, numWords);
	}
    else{
        printResults(wordBank, 0);
    }
}
