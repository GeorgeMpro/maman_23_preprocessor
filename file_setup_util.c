#include "file_setup_util.h"

/*todo*/
/*Attempt to receive pointer to file*/
FILE *getFile(const char *fileName, char *modes) {
    FILE *tmp = fopen(fileName, modes);
    if (tmp == NULL) {
        RETURN_ON_ERROR(ERROR_FILE_NAME, fileName);
        exit(1);
    }
    return tmp;
}

/*Valid name or error*/
void validate_file_name(char *name) {
    if (!is_valid_suffix(name)) {
        RETURN_ON_ERROR(ERROR_FILE_SUFFIX, name);
        exit(1);
    }
}

/*Validates proper file suffix in C*/
int is_valid_suffix(const char *name) {
    char *suffix;
    unsigned long length;
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


/*todo*/
FILE *createOutFile(char *nameToModify, char suffix, char *modes) {
    char *fileName = appendSuffix(nameToModify, suffix);
    /*append name suffix*/
    printf("\n****************************************ull?");
    FILE *tmp = fopen(NULL, modes);
    if (tmp == NULL) {
        RETURN_ON_ERROR(ERROR_FILE_CREATE, fileName)
    }


    return NULL;
}

/*todo*/
char *appendSuffix(char *modify, char suffix) {
    char *tmp;
    unsigned long length = strlen(modify);
    /*todo error handling*/
    /*adding character and trailing zero*/
    tmp = calloc(length + 1 + 1, sizeof(char));
    strcpy(tmp, modify);
    tmp[length] = suffix;
    tmp[length + 1] = '\0';

    return tmp;

}
