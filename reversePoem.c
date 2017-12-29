/* Vicky Mohammad
 * January 18, 2017
 * This program ask the user to write a poem
 * and reverse the poem */

/*import libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int main(){
	/*declare var*/
	char **string;
	int numLine =  1;
	int totalLine = 0;
	int exit = 0;
	int x;
	/*allocate a string array*/
	string = malloc(sizeof(char *) * numLine);
	for (x=0;x<numLine;x++){
		string[x] = malloc(sizeof(char) * 1001);
	}/*end of for loop for allocationg the string*/
	/*ask the user to input the poem*/
	printf("\nEnter the poem: \n");
	fgets(string[numLine-1], 1001, stdin);
	/*infinite loop until user input period on a new line*/
	while(exit == 0){
		/*count a new line for the next*/
		numLine = numLine + 1;
		/*reallocate a new string for the next line*/ 
		string = realloc(string, sizeof(char *) * numLine);
		string[numLine-1] = malloc(sizeof(char) * 1001);
		/*get string from input*/
		fgets(string[numLine-1], 1001, stdin); 
		/*exit when user input period*/
		if (string[numLine-1][0] == '.'){
			exit = 1;
		}/*end of if*/
	}/*end of while loop when user input period*/
	totalLine = numLine;
	/*print the poem in reverse*/
	while(totalLine != 1){
		totalLine = totalLine - 1;
		printf("%s", string[totalLine-1]);
	}/*end of for loop for allocationg the string*/
	/*free all memory*/
	for(x=0;x<numLine-1;x++){
		free(string[x]);
	}/*end for*/
	free(string);
	return(0);
}/*end of main*/
