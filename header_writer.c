#include "header_writer.h"

void write_header_contents_to_file(char *name, FILE *out) {
    char buffer[BUFFER_MAX_SIZE];
    FILE *tmp;
    tmp = get_file(name, READ_MODE);
    while (!feof(tmp)) {
        fgets(buffer, sizeof(buffer), tmp);
        fputs(buffer, out);
    }


    fclose(tmp);
}

/*Extract file name from header declaration*/
char *extract_file_name(char *buffer) {
    char *token;
    token = strtok(buffer, " ,\t\n");
    while (token != NULL) {
        if (strstr(token, ".h")) {
            return token;
        }
        token = strtok(NULL, "\"\n");
    }
    return token;
}

void check_if_library(char *buffer, FILE *out) {
    char *headerName;
/*todo*/
    /*Most likely a library*/
    if (strstr(buffer, "#") && strstr(buffer, "include") && strstr(buffer, "printf(") == NULL) {
        headerName = extract_file_name(buffer);
        write_header_contents_to_file(headerName, out);
    } else {
        fputs(buffer, out);
    }
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