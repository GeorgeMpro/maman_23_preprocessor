#include "comment_remover.h"

enum state {
    IN_COMMENT, OUT, IN_STRING, LEFT_SLASH, RIGHT_STAR
};

FILE *write_file_without_comments(FILE *in, FILE *out);

/*todo move to reader/writer*/
FILE * generate_comment_free_file(char *fileName) {

    FILE *in = NULL, *out = NULL;

    /*Get pointer to file is possible*/
    in = getFile(fileName, READ_MODE);
    out = createOutFile(fileName, FILE_NO_COMMENT, "w");

/*todo uncomment
 * switch cases? in, out, comment in comment?*/
    /*Reading and writing to file*/

    /*todo clear memory, also file pointers*/

    return write_file_without_comments(in, out);

}

/*Write file without comments */
FILE *write_file_without_comments(FILE *in, FILE *out) {
    int ch, state;
    state = OUT;
    while ((ch = fgetc(in)) != EOF) {
        switch (state) {
            case OUT:
                if (ch == '/') {
                    state = LEFT_SLASH;
                } else {
                    putc(ch, out);
                    if (ch == '\"') {
                        state = IN_STRING;
                    }
                }
                break;

            case LEFT_SLASH:
                if (ch == '*') {
                    state = IN_COMMENT;
                }
                break;

            case IN_COMMENT:
                if (ch == '*') {
                    state = RIGHT_STAR;

                }
                break;

            case RIGHT_STAR:
                if (ch == '/') {
                    state = OUT;
                } else {
                    state = IN_COMMENT;
                }
                break;
            case IN_STRING:
                if (ch == '\"') {
                    state = OUT;
                }
                putc(ch, out);
                break;
        }
        /*todo del*/
        printf("%c:%d", ch, ch);
    }
    return out;
}

