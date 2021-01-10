#include "comment_remover.h"



/*todo move to reader/writer*/

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

