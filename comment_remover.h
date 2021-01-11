/*Libraries*/
#include "file_setup_util.h"

/*Definitions*/
#define READ_MODE "r"

#define WRITE_MODE "w"

#define IS_SLASH ch == '/'

#define IS_STAR ch == '*'

#define IS_QUOTE ch=='\"'

/*Current character state while reading input file*/
enum state {
    IN_COMMENT, OUT, IN_STRING, LEFT_SLASH, RIGHT_STAR
};

/*Functions*/
FILE *generate_comment_free_file(char *fileName);

FILE *write_file_without_comments(FILE *in, FILE *out);

int check_out_state_change(FILE *out, int ch, int state);

int check_string_state(int ch, int state);

int check_star_state(int ch, int state);

int check_slash_state(int ch, int state);
