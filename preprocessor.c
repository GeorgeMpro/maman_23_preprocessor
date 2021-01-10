/*todo move*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
/*todo extract*/
#define MAX_BUFFER 500

#define FILE_NO_COMMENT '1'


/*todo move to reader/writer*/
int is_valid_suffix(const char *name);

FILE *getFile(const char *fileName, char *modes);

FILE *createOutFile(char *nameToModify, char suffix, char *modes);

char *appendSuffix(char *modify, char suffix);

int remove_comments(char *fileName) {
/*todo
 * validate file name ends with .c
 * go to sizeof and see whats the 2 last chars with strcompare?
 * strrchr?*/

    /*todo clean comments */
    int ch;
    FILE *in = NULL, *out = NULL;
    /*todo make dynamically allocate*/
    char buffer[MAX_BUFFER];

    /*todo open for reading and get chars*/
    /*Get pointer to file is possible*/
    in = getFile(fileName, "r");
    out = createOutFile(fileName, FILE_NO_COMMENT, "w");

/*todo uncomment*/
/*
    while (!feof(in)) {
        ch = fgetc(in);

        printf("%c:%d", ch, ch);
    }
*/

    /*todo clear memory, also file pointers*/
    return 0;
}

/*todo*/
/*Attempt to receive pointer to file*/
FILE *getFile(const char *fileName, char *modes) {
    FILE *tmp = fopen(fileName, modes);
    if (tmp == NULL) {
        RETURN_ON_ERROR(ERROR_FILE_NAME, fileName);
        exit(1);
    }
    return tmp;
}

/*todo*/
FILE *createOutFile(char *nameToModify, char suffix, char *modes) {
    char *fileName = appendSuffix(nameToModify, suffix);
    /*append name suffix*/
    printf("\n****************************************ull?");
    FILE *tmp = fopen(NULL, modes);
    if (tmp == NULL) {
        RETURN_ON_ERROR(ERROR_FILE_CREATE, fileName)
    }


    return NULL;
}

/*todo*/
char *appendSuffix(char *modify, char suffix) {
    char *tmp;
    unsigned long length = strlen(modify);
    /*todo error handling*/
    /*adding character and trailing zero*/
    tmp = calloc(length + 1 + 1, sizeof(char));
    strcpy(tmp, modify);
    tmp[length] = suffix;
    tmp[length + 1] = '\0';

    return tmp;

}

/*Valid name or error*/
void validate_file_name(char *name) {
    if (!is_valid_suffix(name)) {
        RETURN_ON_ERROR(ERROR_FILE_SUFFIX, name);
        exit(1);
    }
}

/*Validates proper file suffix in C*/
int is_valid_suffix(const char *name) {
    char *suffix;
    unsigned long length;
    /*Get last appearance of 'c' and the character before in file name*/
    suffix = strrchr(name, 'c');
    suffix--;

    /*Validate last 2 locations in name character array*/
    length = strlen(name) - 1;

    return suffix != NULL
           && strcmp(suffix, ".c") == 0
           && name[length] == 'c'
           && name[--length] == '.';
}

int main(int argc, char *argv[]) {
/*Todo, provide instructions
 * current folder file -        name.c
 * 1 remove comments -          name.c1
 * 2 write #define file insidein        name.c2*/
/*todo del*/
    int i;
    char *fileName;
    for (i = 0l; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    /*Validate number of given number of arguments*/
    if (argc != 2) {
        printf("\n%d", argc);
        RETURN_ON_ERROR(ERROR_WRONG_ARG_NUMBER, argc)
    }
    fileName = argv[1];

    validate_file_name(fileName);


    remove_comments(fileName);
/*todo write non commented filename.c1 */

/*todo write file with input #include fields filename.c2*/

    /*todo del, examples from dani  *
    int x = 16961;
    printf("\n%d", x);
    putchar('\n');
    fwrite(&x, sizeof(int), 1, stdout);
*/

    /*Program complete successfully*/
    /*todo clear memory*/
    return 0;
}
/*todo
 *          get arguments from user
 *          read file - from argv[1]
 *                  1. name can be 500 long
 *                  2. can include dots '.' before .c
 *                  3. start from the end, make sure it starts with c then . (going backwards)
 *          deal with error not reading
 *                  1. stderr or send error
 *          close and clear memory*/

/*todo
 * on valid file name
 * create new file with some suffix to write to*/

/*todo
 *          read include
 *          1. deal with normal #
 *          2. ignore spaces and tabs
 *          3. look for comments*/
/*TODO
 * first read only the file
 *          maybe r+/r go over the difference
 *          handle errors and exceptions
 *          Give information
 *          Note: windows/linux enter differenence - wds 2 bits(10 and 13), lnx 1 bit
 * process the file
 *          use the location to understand when start of comment
 *          when end of comment
 *          calc the distance and ignore it in writing the new file
 *                  1. single line comments
 *                  2. multi line comments
 *                  3. comments that are part of an existing line of text
 *          */

/*todo          when finding # and ** return a pointer to the location *
*          with fgetpos , fsetpos
*          remember when comment starts in mid sentence with location(do not read after
*          Maybe remember the distance from each point/from the begining with fseek
* alternatively, jum and ignore the comments - remember where they are and then jump over and write afterwards
*                  1. find start comment
*                  2. if whole line comment
*                  3. if multi line comment
*                  4. if comment as part of the text
*                  5. deal with printf("\n%d", x);
* */