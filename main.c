#include <stdlib.h>
#include <stdio.h>
#define MAX_LENGTH 1024										//Define a max length for the sentence

#include "hashing.h"
#include "cmd.h"
#include "nature.h"

int main(){
	char inp[MAX_LENGTH];									//Define the needed sentence string
	printf("Hal 9001 Has Been Initialised... \n>> ");
	
	while(1){												//Run the command line in a perpetual loop
		cmd(inp);											//Check for user input
		nature(inp);										//Check for nature of input
	}

	return 0;
}
