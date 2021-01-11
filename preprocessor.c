/*todo move*/
#include <stdio.h>
#include "comment_remover.h"


void generate_file_with_written_libraries(char *name, FILE *in) {
    FILE *out;
    /*todo*/
    out = create_out_file(name, '2', WRITE_MODE);


/*todo
 * ***not forget to error check everywhere
 *          open for writing
 * 1. find #include location
 *          set start pointer
 *          set end pointer
 * 2. extract the file name value
 *          open the file
 *          copy file contents
 *                  copy whole lines*/

}

int main(int argc, char *argv[]) {
    char *fileName;
    FILE *noComment;

    /*todo user friendly explanation*/

    fileName = get_file_name(argc, argv);
    /*Validate if valid .c file name*/
    validate_file_name(fileName);

/*todo validate not null*/
    noComment = generate_comment_free_file(fileName);

    generate_file_with_written_libraries(fileName, noComment);



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