#include "header_writer.h"

/*Create file for library content insertions*/
void generate_file_with_written_libraries(FILE *in, char *name) {
    FILE *out;

    out = create_out_file(name, INSERTED_CONTENT_SUFFIX, WRITE_MODE);
    insert_includes(in, out);
}


/*Write header content to the output file*/
void insert_includes(FILE *in, FILE *out) {
    char buffer[BUFFER_MAX_SIZE];

    /*Rewind passed file to the beginning*/
    rewind(in);
    while (!feof(in)) {
        fgets(buffer, sizeof(buffer), in);
        process_input_file_line(out, buffer);
    }

    /*Close .c2 file*/
    fclose(out);
}

/*Decide how to copy input line to output*/
void process_input_file_line(FILE *out, char *buffer) {
    /*Check for header in stream or copy the line wholly*/
    (strstr(buffer, "include") != NULL) ?
    check_if_library(buffer, out) : fputs(buffer, out);
}

/*Validate need to extract header file information*/
int check_if_library(char *buffer, FILE *out) {
    char *headerName;

    /*Check if string is an an include*/
    if (strstr(buffer, "#")
        && strstr(buffer, "include")
        && strstr(buffer, "printf(") == NULL) {

        headerName = extract_file_name(buffer);
        write_header_contents_to_file(headerName, out);
    } else {
        fputs(buffer, out);
    }
    return 0;
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

/*Insert comments to given file*/
void write_header_contents_to_file(char *name, FILE *out) {
    FILE *tmp;
    char buffer[BUFFER_MAX_SIZE];
    tmp = get_file(name, READ_MODE);
    while (!feof(tmp)) {
        fgets(buffer, sizeof(buffer), tmp);
        fputs(buffer, out);
    }

    fclose(tmp);
}
