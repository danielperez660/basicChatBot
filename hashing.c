#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "hashing.h"

char ** hashing(char x[], int spaces){
	int i, j, lng, strt, wrds;
	char ** sub_str = malloc((spaces+1) * sizeof(char*));													//Define the size of the array of strings
	char * temp;
	
	i = strt = lng = wrds = j = 0;

	for (i; i < strlen(x)+1; i++, lng++){																	//Run through the sub strings of the sentence

		if(x[i] == 32 || i == strlen(x)){																	//A space is reached so the word has to be hashed
			
			sub_str[wrds] = malloc((lng) * sizeof(char));													//Creates a variable space for the string withing the string array
			temp = malloc(lng*sizeof(char));
			
			for(strt, j = 0; strt < i; strt++){
				if(x[strt] != ' ' && x[strt] != ','&& x[strt] != '?'&& ((x[strt] < 58 && x[strt] > 47)||(x[strt] < 123 && x[strt] > 64))){	//Making sure that it is not a symbol
					x[strt] = tolower(x[strt]);
					temp[j] = x[strt];
					j++;
				}
				
			}

			sub_str[wrds] = temp;
			strt = i;				
			wrds++;
			lng = 0;

		}
   	}
   	
   				
   	
	return sub_str;
}
