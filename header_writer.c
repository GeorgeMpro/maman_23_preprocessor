#include "header_writer.h"

void header_name_extractor(FILE *in, char *buffer, fpos_t *fpos, fpos_t *poundPos, int ch, long newLineStart) {
    char *token;
    /*todo first token*/
    printf("\nHEAD buffer %s", buffer);
    token = strtok(buffer, " ,\t\n");

    printf("\nTOKEN:[%s]", token);


    token = strtok(NULL, " ,\t\n");
    printf("\nTOKEN:[%s]", token);
    printf("\nnew line: %ld", newLineStart);
/*
    newLineStart = ftell(in);
*//*todo sets to start of current line
 * maybe use fseek instead?*//*
    fsetpos(in, fpos);
    printf("\n***buffer: [%s]", buffer);
    printf("\n***Start char stream\n");

    do {
        *//*todo get # location*//*
        ch = fgetc(in);
        if (ch == '#') {
            fgetpos(in, poundPos);

        }
        putchar(ch);
    } while (ch != '\n');


    fgetpos(in, fpos);*/
}

/*Write header content to the output file*/
void insert_includes(FILE *in, FILE *out) {
    /*todo*/
    char *token;
    char buffer[BUFFER_MAX_SIZE];
    fpos_t fpos, poundPos;
    int ch;
    /*Rewind passed file to the beginning*/
    rewind(in);

    long newLineStart;


    /*todo
     * make sure no weird chars or EOF*/
/*todo points to start*/
/*todo reset stream
 * */
    fgetpos(in, &fpos);
    while (!feof(in)) {
        fgets(buffer, sizeof(buffer), in);
        /*todo
         * points to beginning of the line*/
        /*todo do not copy char by char
         * else copy char by char*/
        printf("\nbuffer:[%s]", buffer);
        if (strstr(buffer, "include") != NULL) {
            header_name_extractor(in, buffer, &fpos, &poundPos, ch, newLineStart);

            /*Copy the buffer into .c2 out file*/
        } else {
            fputs(buffer, out);
        }


    }


}

void generate_file_with_written_libraries(FILE *in, char *name) {
    FILE *out;
    /*todo*/
    out = create_out_file(name, INSERTED_CONTENT_SUFFIX, "w");
    insert_includes(in, out);


}