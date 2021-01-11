/*todo move*/
#include <stdio.h>
#include "comment_remover.h"


int main(int argc, char *argv[]) {
    char *fileName;
    FILE *noComment;

    /*todo user friendly explanation*/

    fileName = get_file_name(argc, argv);
    /*Validate if valid .c file name*/
    validate_file_name(fileName);

/*todo validate not null*/
    noComment = generate_comment_free_file(fileName);

/*todo
 * ***not forget to error check everywhere
 * Create new file
 *          set fileName.c2
 *          open for writing
 * 1. find #include location
 *          set start pointer
 *          set end pointer
 * 2. extract the file name value
 *          open the file
 *          copy file contents
 *                  copy whole lines*/

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