/*todo move*/
#include <stdio.h>
#include "comment_remover.h"
#include "header_writer.h"


int main(int argc, char *argv[]) {
    char *inputFile, *noComment;

    /*todo user friendly explanation*/

    inputFile = get_file_name(argc, argv);
    /*Validate if valid .c file name*/
    validate_file_name(inputFile);

/*todo validate not null*/
/*todo free the in file, maybe in the other file*/
    noComment = generate_comment_free_file(inputFile);

    generate_file_with_written_libraries(noComment, inputFile);



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