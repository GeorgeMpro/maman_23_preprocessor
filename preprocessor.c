#include "comment_remover.h"
#include "header_writer.h"


/*Program that removes comments and writes in header file content for given file*/
int main(int argc, char *argv[]) {
    char *inputFile;
    FILE *noComment;

    /*todo user friendly explanation*/

    /*Extract file name from user arguments*/
    inputFile = get_file_name(argc, argv);

    /*Validate if valid .c file name*/
    validate_file_name(inputFile);

    /*Write non-commented file with .c1 suffix*/
    noComment = generate_comment_free_file(inputFile);

    /*Write file containing the contents of included header files*/
    generate_file_with_written_libraries(noComment, inputFile);


    fclose(noComment);
    return 0;
}