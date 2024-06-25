#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>


/**
 * @brief count the characters in the input file 
 * 
 * @param fptr a pointer to the input file
 * @return int the number of charactesr int he file (based on the locale)
 */
int countChars(FILE *fptr){
    int chars = 0; 
    int c; 
    while((c=fgetwc(fptr))!= WEOF){
        chars++;
    }

    return chars;
}

/**
 * @brief count the number of words in the input file
 * 
 * @param fptr a pointer to the input file
 * @return int number of the words in the file
 */
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

/**
 * @brief count number of lines in the input file
 * 
 * @param fptr a pointer to the file
 * @return int number of the lines in the file
 */
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

/**
 * @brief count the number of bytes in the file
 * 
 * @param fptr a pointer to the file
 * @return int number of bytes in the file
 */
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

/**
 * @brief control the flow of the operations
 * 
 * @param fptr a pointer to the file
 * @param operation the operation to done 
 * @param filename the file name to print in the output message
 */

void WC(FILE *fptr, char operation, char* filename){
    int chars; 
    int bytes; 
    int lines; 
    int words;
    switch (operation)
    {
    case 'c':
        bytes = numBytes(fptr);
        printf("%d\t%s\n", bytes, filename);
        break;

    case 'l':
        lines = numLines(fptr);
        printf("%d\t%s\n", lines, filename);
        break;

    case 'w': 
        words = numWords(fptr);
        printf("%d\t%s\n", words, filename);
        break;
    
    case 'm':
        chars = countChars(fptr);
        printf("%d\t%s\n", chars, filename);
        break;

    default:

        break;
    }
}


void handleStandardInput(int argc, char* argv[]){
    FILE* fptr = stdin;
    if(argc == 1){
        int bytes = numBytes(fptr);
        fseek(fptr, 0, SEEK_SET);
        int lines = numLines(fptr);
        fseek(fptr, 0, SEEK_SET); 
        int words = numWords(fptr); 
        printf("%d\t%d\t%d\n", lines, words, bytes);
    }
    else if(argc==2){
        if(strcmp(argv[1], "-c") == 0){
            int bytes = numBytes(fptr);
            printf("%d\n", bytes);
        }

        if(strcmp(argv[1], "-l") == 0){
            int lines = numLines(fptr);
            printf("%d\n", lines);
        }

        if(strcmp(argv[1], "-w") == 0){
            int words = numWords(fptr);
            printf("%d\n", words);
        }
    
        if(strcmp(argv[1], "-m") == 0){
            int chars = countChars(fptr);
            printf("%d\n", chars);
        }
        
    }
    fclose(fptr);
    exit(EXIT_SUCCESS);
}

void main(int argc, char* argv[])
{
    
    setlocale(LC_ALL, "en_US.utf8"); //set the locale for the program 
    
    FILE *fptr; //only 1 file availble to read 
    char *operation;
    
    if (!isatty(fileno(stdin))) {
        handleStandardInput(argc, argv);
    }
    //no argument ir provided (Neither a file nor an argument)
    if(argc == 1){
        printf("use -h for help");
        exit(EXIT_FAILURE);
    }

    
    if(argc == 2){
        fptr = fopen(argv[1], "r");
        int bytes = numBytes(fptr);
        fseek(fptr, 0, SEEK_SET);
        int lines = numLines(fptr);
        fseek(fptr, 0, SEEK_SET); 
        int words = numWords(fptr); 
        printf("%d\t%d\t%d\t%s\n", lines, words, bytes, argv[1]);
        fclose(fptr);
        exit(EXIT_SUCCESS);
    }

    fptr = fopen(argv[2], "r");

    if(fptr == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if(strcmp(argv[1], "-c") == 0){
        WC(fptr, 'c', argv[2]);
    }

    if(strcmp(argv[1], "-l") == 0){
        WC(fptr, 'l', argv[2]);
    }

    if(strcmp(argv[1], "-w") == 0){
        WC(fptr, 'w', argv[2]);
    }
    
    if(strcmp(argv[1], "-m") == 0){
        WC(fptr, 'm', argv[2]);
    }

    fclose(fptr);
    exit(EXIT_SUCCESS);

}

