#include "file_setup_util.h"

/*Extract file name from user input*/
char *get_file_name(int argc, char **argv) {
    /*Validate number of given number of arguments*/
    if (argc != NUMBER_OF_ALLOWED_ARGUMENTS) {
        RETURN_ON_ERROR(ERROR_WRONG_ARG_NUMBER, argc)
    }
    return argv[1];
}

/*Attempt to receive pointer to file*/
FILE *get_file(char *fileName, char *modes) {
    FILE *tmp;
    tmp = fopen(fileName, modes);
    if (tmp == NULL) {
        RETURN_ON_ERROR(ERROR_FILE_NAME, fileName)
        exit(1);
    }
    return tmp;
}

/*Valid name or error*/
void validate_file_name(char *name) {
    if (!is_valid_suffix(name)) {
        RETURN_ON_ERROR(ERROR_FILE_SUFFIX, name)
        exit(1);
    }
}

/*Validates proper file suffix in C*/
int is_valid_suffix(char *name) {
    char *suffix;
    size_t length;
    /*Get last appearance of 'c' and the character before in file name*/
    suffix = strrchr(name, 'c');
    suffix--;

    /*Validate last 2 locations in name character array*/
    length = strlen(name) - 1;

    return suffix != NULL
           && strcmp(suffix, ".c") == 0
           && name[length] == 'c'
           && name[--length] == '.';
}

/*Create new file or overwrite existing.*/
FILE *create_out_file(char *nameToModify, char suffix, char *modes) {
    char *fileName;
    FILE *tmp;

    /*append file name suffix*/
    fileName = append_suffix(nameToModify, suffix);
    tmp = fopen(fileName, modes);
    if (tmp == NULL) {
        RETURN_ON_ERROR(ERROR_FILE_CREATE, fileName)
    }

    return tmp;
}

/*Append character to given string*/
char *append_suffix(char *modify, char suffix) {
    char *tmp;
    size_t length;
    length = strlen(modify);

    /*adding character and trailing zero*/
    tmp = calloc(length + 1 + 1, sizeof(char));
    if (tmp == NULL) {
        perror("\nERROR:Could not allocate memory for file name appending suffix");
        exit(1);
    }

    strcpy(tmp, modify);
    tmp[length] = suffix;
    tmp[length + 1] = '\0';

    return tmp;
}
