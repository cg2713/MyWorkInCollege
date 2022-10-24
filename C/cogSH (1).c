/*
 * Name			: Christopher Garcia
 * Class		: CS-221 OA
 * Semester		: spring 2020
 * This File	: cogSH.c
 *
 * Description	: this program is like simpleREPL but it has a command in place to withc it will change the prompt 
 * output
 * 
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * getString();
void chgP(char* newPromted, char** oldPromped);

int main(int argc, char *argv[]){
    char * prompt = "enter a message> "; // promt is a tring so that it can be changed later if the user would like
    char *currentDirectory;
	while (1){
		printf("%s", prompt);
        
        
        
		char *userStr = getString(); // gets user input
        chgP(userStr, &prompt);

        
        
        
		char *EX = "exit"; // test for exit only

		if(strcmp(userStr,EX) == 0){
			break;
		}
		printf("%s\n", userStr);
	}
}

void chgP(char* newPromted, char** oldPromped){
    char* userStr = newPromted;
    char* prompted;
    char* newPromt = "export PS1=\"";
    char* newPromt2 = "PS1=\"";
    char *test = (char*)malloc(sizeof(userStr)); // to test if the user used PS1="" or "export PS1=""
    int t = 0;
    if(userStr[0] == 'e'){ // this test for prompt 1 incase the user desides to use export PS1=""
        for(int i = 0; i <= strlen(newPromt); i++){
            for(int j = 0; j <= strlen(userStr); j++){
                if(newPromt[i] == userStr[j]){
                    test[t] = newPromt[i];
                    t++;
                    break;
                }
            }
        }
    }
    else{// this test for prompt 1 incase the user desides to use PS1=""
        
        for(int i = 0; i <= strlen(newPromt2); i++){
            for(int j = 0; j <= strlen(userStr); j++){
                if(newPromt2[i] == userStr[j]){
                    test[t] = newPromt2[i];
                    t++;
                    break;
                }
            }
        }
    }
    
    t--;
    int j = 0;
    if(strcmp(newPromt, test) == 0){ // this will officially change the promt
        prompted = (char*)malloc(sizeof(userStr));
        while(1){
            //printf("test");
            oldPromped[j] = &userStr[t];
            j++;
            t++;
            if(userStr[t] == '"'){
                break;
            }
        }
    }
    if(strcmp(newPromt2, test) == 0){ // as will this this is here to change the promt in case the user did PS1=""
        prompted = (char*)malloc(sizeof(userStr));
        while(1){
            if(userStr[t] != '"'){
                //printf("test");
                oldPromped[j] = &userStr[t];
                j++;
                t++;
                if(userStr[t] == '"'){
                    break;
                }
            }
        }
    }
    oldPromped = &prompted;
}

char * getString(){
	//make sure the caller is a char *
	char* dest = NULL;
	unsigned long read;
	unsigned long inIt;
	read = getline(&dest,&inIt, stdin);
	dest[read-1] = '\0';
	return dest;
}
