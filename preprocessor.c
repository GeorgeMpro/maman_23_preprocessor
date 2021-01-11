/*todo move*/
#include <stdio.h>
#include "comment_remover.h"

char *get_file_name(int argc, char **argv) {
    /*Validate number of given number of arguments*/
    if (argc != 2) {
        RETURN_ON_ERROR(ERROR_WRONG_ARG_NUMBER, argc)
    }
    return argv[1];
}

int main(int argc, char *argv[]) {
    char *fileName;
    FILE *noComment;
    fileName = get_file_name(argc, argv);

    validate_file_name(fileName);

/*todo validate not null*/
    noComment = generate_comment_free_file(fileName);

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