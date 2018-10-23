#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define GREETS 8
#define EXIT 4
#define AGREE 4
#define JOY 6
#define ASS 3

#include "hashing.h"

int greetings(int r, char *str);
int question(int r, char *str);
int agreement(int r, char *str);
int joy(int r, char *str);
int assumptions(int r, char *str);
void defaults(int r);
void exitss(int r, char *str);
void clear();

char *greet[GREETS] = {"hello", "greetings", "hi", "hey", "hy", "greeting", "hallo", "howdy"};			//General database of greeting
char *exits[EXIT] = {"bye", "goodbye", "adios", "adieu"};												//General database of good byes
char *joys[JOY] = {"good", "great", "happy", "joy", "glad", "amazing"};									//General database of 'joy'
char *assumption[ASS] = {"guess", "assume", "assumption"};												//General database of agreements
char *agree[AGREE] = {"yea", "sure", "ok", "okay"};														//General database of agreements

void nature(char x[]){
	int i = 0;
	int spaces = 0;
	int s;
	char** str;
	srand(time(0));																						//Defining a random number to select the choice of response
	int r = rand();

	for(i; i < strlen(x); i++){																			//Check for max ammount of words for the hashing
		if(x[i] == 32 && x[i-1] != 32){ spaces++;}
	}
		
	str = hashing(x, spaces);																			//Array of strings created locally
	s = r%10;
	
	for(i = 0; i < spaces+1; i++){																		//Checks what the nature of the response is and sets i to illegal value
		if(joy(s, str[i]) == 1){i = -1; break;}
		else if(assumptions(s, str[i]) == 1){i = -1; break;}
		else if(question(s, x) == 1){i = -1; break;}
		else if(greetings(s, str[i]) == 1){i = -1; break;}
		else if(agreement(s, str[i]) == 1){i = -1; break;}
		else{exitss(s, str[i]);}
	}
	
	if(i != -1){
		defaults(s);																					//Default case is run if there is no known response to the input
	}	
	
	printf(">> ");																						//New user input tab
}

int joy(int r, char *str){
	int j = 0;
	
	for(j = 0; j < JOY; j++){																		//Checks if it is a greeting 
		if(strcmp(joys[j], str) == 0 && r < 3){														//Select response from multiple choices
			printf("Hal 9001: Well I'm glad to hear that!\n");
			clear();
			return 1;
		}else if(strcmp(joys[j], str) == 0 && r < 7 && r > 2){
			printf("Hal 9001: Your happiness fills me with robot joy.\n");
			clear();
			return 1;
		}else if(strcmp(joys[j], str) == 0 && r > 6){
			printf("Hal 9001: I am very happy for you!\n");
			clear();
			return 1;
		}
	}
	return 0;
}

int assumptions(int r, char *str){
	int j = 0;
	
	for(j = 0; j < ASS; j++){																		//Checks if it is a greeting 
		if(strcmp(assumption[j], str) == 0 && r < 3){														//Select response from multiple choices
			printf("Hal 9001: I guess.\n");
			clear();
			return 1;
		}else if(strcmp(assumption[j], str) == 0 && r < 7 && r > 2){
			printf("Hal 9001: You could be right.\n");
			clear();
			return 1;
		}else if(strcmp(assumption[j], str) == 0 && r > 6){
			printf("Hal 9001: That would not be a rash assumption.\n");
			clear();
			return 1;
		}
	}
	return 0;
}

int greetings(int r, char *str){
	int j = 0;

	for(j = 0; j < GREETS; j++){																			//Checks if it is a greeting 
		if(strcmp(greet[j], str) == 0 && r < 6){														//Select response from multiple choices
			printf("Hal 9001: Well, greetings to you too sir! How are you doing on this fine day?\n");
			clear();
			return 1;
		}else if(strcmp(greet[j], str) == 0 && r > 5){
			printf("Hal 9001: Howdy sir! How are you doing today?\n");
			clear();
			return 1;
		}
	}
	return 0;
}

int question(int r, char *str){
	int i = 0;

	for(i = 0; i < strlen(str); i++){
		if(str[i] == '?' && r < 3){														//Select response from multiple choices
			printf("Hal 9001: Oh, I'm not really sure.\n");
			clear();
			return 1;
		}else if(str[i] == '?' && r < 5 && r > 2){
			printf("Hal 9001: Is that what humans call a question? Sorry, I'm horrible at answering questions.\n");
			clear();
			return 1;
		}else if(str[i] == '?' && r > 4 && r < 7){
			printf("Hal 9001: Was that directed at me?\n");
			clear();
			return 1;
		}else if(str[i] == '?' && r > 8 && r < 11){
			printf("Hal 9001: No.\n");
			clear();
			return 1;
		}else if(str[i] == '?' && r > 8 && r < 9){
			printf("Hal 9001: Yes.\n");
			clear();
			return 1;
		}
	}
	return 0;
}

int agreement(int r, char *str){
	int i = 0;

	for(i = 0; i < AGREE; i++){
		if(strcmp(agree[i], str) == 0 && r < 6){												//Select response from multiple choices
			printf("Hal 9001: Good.\n");
			clear();
			return 1;
		}else if(strcmp(agree[i], str) == 0 && r > 5){
			printf("Hal 9001: I'm glad we agree.\n");
			clear();
			return 1;
		}
	}
	return 0;
}

void defaults(int r){

	if(r < 3){
		printf("Hal 9001: Huh...\n");
		clear();
	}else if(r < 5 && r > 2){
		printf("Hal 9001: Interesting.\n");
		clear();
	}else if(r < 7 && r > 4){
		printf("Hal 9001: What are you trying to say?\n");
		clear();
	}else if(r < 9 && r > 6){
		printf("Hal 9001: I'm not too sure if I understood that.\n");
		clear();
	}else if(r > 8){
		printf("Hal 9001: I'm guessing that's an opinion?\n");
		clear();
	}
}

void exitss(int r, char *str){
	int j = 0;

	for(j = 0; j < EXIT; j++){																				//Checks if it is a greeting 
		if(strcmp(exits[j], str) == 0 && r < 6){														//Select response from multiple choices
			printf("Hal 9001: Oh, well goodye then.\n");
			exit(0);
		}else if(strcmp(exits[j], str) == 0 && r > 5){
			printf("Hal 9001: See you next time!\n");
			exit(0);
		}
	}
}

void clear(){    																						//Clears the scanf buffer
  while(getchar() != '\n');
}
