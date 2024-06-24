#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>


int numWords(FILE *fptr){
    char tempString[100];
    int counter = 0;
    int inWord = 0;

    while(fgets(tempString, sizeof(tempString), fptr)){
        for(int i =0; i< sizeof(tempString); i++){
            if(tempString[i]=='\0'){
                break;
            }

            if(isspace(tempString[i])){
                if(inWord){
                    counter++;
                    inWord=0;
                }
            }else{
                inWord = 1;
            }
        }
    }

    if(inWord){
        counter++;
    }
    return counter;
}

int numLines(FILE *fptr){
    char tempString[100];
    int counter = 0;
    while(fgets(tempString, sizeof(tempString), fptr)){
        for(int i =0; i< sizeof(tempString); i++){
            if(tempString[i] == '\0')
                break;
            if(tempString[i] == '\n')
                counter++;
        }
    }

    return counter;
}
int numBytes(FILE *fptr){

    char tempString[100];
    int counter = 0;
    while(fgets(tempString, sizeof(tempString), fptr)){
        for(int i =0; i< sizeof(tempString); i++){
            if(tempString[i] == '\0')
                break;

            counter++;
        }
    }

    return counter;
}
void main(int argc, char* argv[])
{
    if(argc == 1){
        perror("use -h for help");
        exit(EXIT_FAILURE);
    }

    if(argc == 2){
        FILE* fptr = fopen(argv[1], "r");
        int bytes = numBytes(fptr);
        fseek(fptr, 0, SEEK_SET);
        int lines = numLines(fptr);
        fseek(fptr, 0, SEEK_SET); 
        int words = numWords(fptr); 
        printf("%d\t%d\t%d\t%s\n", lines, words, bytes, argv[1]);
        fclose(fptr);
        exit(EXIT_SUCCESS);
    }
    
    FILE *fptr;
    fptr = fopen(argv[2], "r");

    if(fptr == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }


    if(strcmp(argv[1], "-c") == 0){
        int bytes = numBytes(fptr);
        printf("%d\t%s\n", bytes, argv[2]);
    }

    if(strcmp(argv[1], "-l") == 0){
        int lines = numLines(fptr);
        printf("%d\t%s\n", lines, argv[2]);
    }

    if(strcmp(argv[1], "-w") == 0){
        int words = numWords(fptr);
        printf("%d\t%s\n", words, argv[2]);
    }
    

    fclose(fptr);
    exit(EXIT_SUCCESS);

}

