/*          Error Messages*/
#define ERROR_WRONG_ARG_NUMBER "\nERROR:Invalid number of arguments %d.\n"
#define ERROR_FILE_NAME "\nERROR:Could not open %s\n"
#define ERROR_FILE_CREATE "\nERROR:Could not create file \"%s\"\n"
#define ERROR_FILE_SUFFIX "\nERROR:Invalid file suffix in %s\n"

/*          Error handling*/
#define RETURN_ON_ERROR(MSG, ARG) \
    printf(MSG,ARG);

