#include <stdio.h>
#include <string.h>
#define P 5
/*
int main(){
	int count = 0;
	char userPhrase[P] = "hello world how are you";
	
	printf("the phrase [%s] has %d words\n", userPhrase, count);


	char * delim =  " \t\n";
	char *s = strtok(userPhrase, delim);
	printf("strtok retuns [%s]\n\n", s);
	s = strtok(NULL, delim);
    count++;
	while((strtok(NULL, delim)) != NULL){
		s = strtok(NULL, delim);
		count++;
		printf("strtok retunrs [%s]\n", s);
	}
	
	printf("the phrase [%s] has %s` words\n", userPhrase, strtok(userPhrase, " \t\n"));

	//printf("please input a string to print");

	
}*/

int main(){
	//char userPhrase[P+1] = "hello \n\n\n world \n how are you?";
	char *userPhrase = NULL;
	char str[P+1];
	//strcopy(str, userPhrase);
	int wc = 0;

	printf("enter a phrase: ");
	fgets(userPhrase, P, stdin);
	
	strcpy(str, userPhrase);
	

	char * delim = " \n\t";
	char *s;
	s = strtok(str, delim);
	wc++;
	while((s = strtok(NULL, delim)) != NULL){
		wc++;
		printf("token: word[%d] = [%s]\n", wc, s);
	}

	printf("the given phrase [%s] has %d words\n", userPhrase, wc);

}
