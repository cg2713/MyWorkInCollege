/*
 * Name			: Christopher Garcia
 * Class		: CS-221 OA
 * Semester		: spring 2020
 * This File	: simpleREPL.c
 *
 * Description	: this program is suppose to mimic the likes of a shell by excepting input but the user and returnign it back to the user
 * 
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * getString();

int main(int argc, char *argv[]){
    char * prompt = "enter a message> ";

	while (1){
		printf("%s", prompt);
        
        char* newPromt = "export PS1=\"";
        char* newPromt2 = "PS1=\"";
        
		char *userStr = getString(); // gets user input
        char *test = (char*)malloc(sizeof(userStr));

        int t = 0;
        
        if(userStr[0] == 'e'){
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
        else{
            
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
        if(strcmp(newPromt, test) == 0){
            prompt = (char*)malloc(sizeof(userStr));
            while(1){
                //printf("test");
                prompt[j] = userStr[t];
                j++;
                t++;
                if(userStr[t] == '"'){
                    break;
                }
            }
        }
        if(strcmp(newPromt2, test) == 0){
            prompt = (char*)malloc(sizeof(userStr));
            while(1){
                if(userStr[t] != '"'){
                    //printf("test");
                    prompt[j] = userStr[t];
                    j++;
                    t++;
                    if(userStr[t] == '"'){
                        break;    
                    }
                }
            }
        }

        /*
        char *copy;
        char *copy2;
        strcpy(copy, userStr);
		char * delim = "export PSI=";
        char * delim2 = "PSI=";
        char* s = strtok(copy, delim);
	    while((s = strtok(NULL, delim)) != NULL){
	    	prompt = s;
	    }
        char* s2 = strtok(copy2, delim);
        while((s2 = strtok(NULL, delim2)) != NULL){
	    	prompt = s2;
	    }*/
        
        

		char *EX = "exit"; // test for exit only

		if(strcmp(userStr,EX) == 0){
			break;
		}
		printf("%s\n", userStr);
	}
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
