/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include "file_setup_util.h"

/*Definitions*/
#define INSERTED_CONTENT_SUFFIX '2'

#define BUFFER_MAX_SIZE 500

#define WRITE_MODE "w"

/*Functions*/
void generate_file_with_written_libraries(FILE *, char *);

void process_input_file_line(FILE *out, char *buffer);

void insert_includes(FILE *, FILE *);

int check_if_library(char *buffer, FILE *out);

char *extract_file_name(char *);

void write_header_contents_to_file(char *, FILE *);