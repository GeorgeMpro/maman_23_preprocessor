/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

/*Declarations*/
#define READ_MODE "r"

#define WRITE_PLUS_MODE "w+"

#define FILE_NO_COMMENT_SUFFIX '1'

#define NUMBER_OF_ALLOWED_ARGUMENTS 2

/*Functions*/
char *get_file_name(int, char **);

int is_valid_suffix(char *);

FILE *get_file(char *, char *);

FILE *create_out_file(char *, char, char *);

char *append_suffix(char *, char);

void validate_file_name(char *);
