#include "header_writer.h"

void check_if_library(char *buffer, FILE *out) {
    char *token;
/*todo*/
    if (strstr(buffer, "#") && strstr(buffer, "include") && strstr(buffer, "printf(") == NULL) {

        printf("\nprobably include");

        /*todo first token*/
        printf("\nHEAD buffer %s", buffer);
        token = strtok(buffer, " ,\t\n");
        while (token != NULL) {
            printf("\nTOKEN:[%s]", token);

            token = strtok(NULL, "\"\n");
        }
    } else {
        fputs(buffer, out);
    }
/*    printf("\nnew line: %ld", newLineStart);*/
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
    char buffer[BUFFER_MAX_SIZE];
    fpos_t fpos;
    /*Rewind passed file to the beginning*/
    rewind(in);
    /*todo del?*/
    fgetpos(in, &fpos);
    while (!feof(in)) {
        fgets(buffer, sizeof(buffer), in);
        /*todo
         * check if include of something else
         * */
        if (strstr(buffer, "include") != NULL) {
            check_if_library(buffer, out);

            /*Copy the buffer into .c2 out file*/
        } else {
            fputs(buffer, out);
        }
    }

    /*todo free/close*/
}

/*Create file for library content insertions*/
void generate_file_with_written_libraries(FILE *in, char *name) {
    FILE *out;
    /*todo*/
    out = create_out_file(name, INSERTED_CONTENT_SUFFIX, "w");
    insert_includes(in, out);
}