#include <stdio.h>

int main(int argc, char *argv[]){
    for(int i = 0; i < argc; i++){
        printf("arg[%02d] %s\n",i, argv[i]);
    }
}
