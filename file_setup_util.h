/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

/*Declarations*/
#define READ_MODE "r"

#define WRITE_PLUS_MODE "w+"

#define FILE_NO_COMMENT_SUFFIX '1'

/*Functions*/
char *get_file_name(int argc, char **argv);

int is_valid_suffix(const char *name);

FILE *getFile(const char *fileName, char *modes);

FILE *create_out_file(char *nameToModify, char suffix, char *modes);

char *append_suffix(char *modify, char suffix);

void validate_file_name(char *name);
