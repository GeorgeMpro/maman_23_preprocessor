/*Libraries*/
#include "file_setup_util.h"

/*Definitions*/
#define IS_SLASH ch == '/'

#define IS_STAR ch == '*'

#define IS_QUOTE ch=='\"'

/*Current input state while reading input file*/
enum state {
    IN_COMMENT, OUT, IN_STRING, LEFT_SLASH, RIGHT_STAR
};

/*Functions*/
FILE *generate_comment_free_file(char *);

FILE *write_file_without_comments(FILE *, FILE *);

int check_out_state_change(FILE *, int, int);

int check_string_state(int, int);

int check_star_state(int, int);

int check_slash_state(int, int);
