#include "comment_remover.h"

enum state {
    IN_COMMENT, OUT, IN_STRING, LEFT_SLASH, RIGHT_STAR
};


/*Generate a copy of given file without ANSI comments*/
FILE *generate_comment_free_file(char *fileName) {
    FILE *in = NULL, *out = NULL;

    /*Get pointer to file is possible*/
    in = getFile(fileName, READ_MODE);
    out = createOutFile(fileName, FILE_NO_COMMENT, WRITE_MODE);

    return write_file_without_comments(in, out);
}

/*Write file without comments */
FILE *write_file_without_comments(FILE *in, FILE *out) {
    int ch, state;
    state = OUT;
    /*Reading and writing to file*/
    while ((ch = fgetc(in)) != EOF) {
        switch (state) {
            case OUT:
                state = check_out_state_change(out, ch, state);
                break;
            case LEFT_SLASH:
            case IN_COMMENT:
                state = check_star_state(ch, state);
                break;
            case RIGHT_STAR:
                state = check_slash_state(ch, state);
                break;
            case IN_STRING:
                state = check_string_state(ch, state);
                putc(ch, out);
                break;
        }
    }
    return out;
}

/*Check if write normally or change state from OUT*/
int check_out_state_change(FILE *out, int ch, int state) {
    if (IS_SLASH) {
        return LEFT_SLASH;
    } else {
        putc(ch, out);
        return check_string_state(ch, state);
    }
}

/*Check state change on * value*/
int check_star_state(int ch, int state) {
    if (IS_STAR) {
        return (state == LEFT_SLASH) ? IN_COMMENT : RIGHT_STAR;
    }
    return state;
}

int check_slash_state(int ch, int state) {
    if (IS_SLASH && state != IN_COMMENT) {
        return (state == OUT) ? LEFT_SLASH : OUT;
    }
    return state;
}

/*Check if keep IN_STRING state*/
int check_string_state(int ch, int state) {
    if (IS_QUOTE) {
        return (state == IN_STRING) ? OUT : IN_STRING;
    }
    return state;
}
