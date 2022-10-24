#include <stdio.h>
#include <string.h>

float perenthesies(int index, char* r);
char * getString();

int main(int argc, char *argv[]){
	while(1){
		char* input = getString();
		char* EX = "exit";
		float result = 0;
		if(strcmp(input,EX) == 0){ 
			break;
		}
		
		for(int i = 0; i <= strlen(input); i++){
			if(input[i] == '('){
				result *= perenthesies(i, input);
			}
			if(isdigit(input[i]))
				result += atoi(input[i]);
			if(input[i] == '+')
				result += atoi(input[i-1]) + atoi(input[i+1]);
			if(input[i] == '*')
				result += atoi(input[i-1]) * atoi(input[i+1]);
			if(input[i] == '/')
				result += atoi(input[i-1]) / atoi(input[i+1]);
			if(input[i] == '-')
				result += atoi(input[i-1]) - atoi(input[i+1]);
				
		}
	}
}
float perenthesies(int index, char* r){
	float total = 1;
	int i = index;
	while(r[i] != ')'){
		if(r[i] == '('){
			total += perenthesies(i, r);
		}
		if(r[i] == '+')
			total += atoi(r[i-1]) + atoi(r[i+1]);
		if(r[i] == '*')
			total += atoi(r[i-1]) * atoi(r[i+1]);
		if(r[i] == '/')
			total += atoi(r[i-1]) / atoi(r[i+1]);
		if(r[i] == '-')
			total += atoi(r[i-1]) - atoi(r[i+1]);
	return total;
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