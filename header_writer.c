#include "header_writer.h"

void insert_includes(FILE *in, FILE *out) {
    /*todo
     * cleanup
     * check error
     * free memmory*/
    char *buffer;
    buffer = calloc(BUFFER_MAX_SIZE, sizeof(char));
    printf("\nanan!!\n");
    fgets(buffer, BUFFER_MAX_SIZE, in);
    printf("buffr: [%s]", buffer);
    while (fgets(buffer, BUFFER_MAX_SIZE, in) != NULL) {
        puts(buffer);
    }


}

void generate_file_with_written_libraries(FILE *in, char *name) {
    FILE *out;
    out = create_out_file(name, INSERTED_CONTENT_SUFFIX, WRITE_PLUS_MODE);

    insert_includes(in, out);

    /*todo
     *      get line
     *      go over line
     *              if has header #include
     *              get pointer to #
     *              pointer to 2nd "
     *              write header content at #
     *              continue reading tokens from 2nd
     *              close library file"*/


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