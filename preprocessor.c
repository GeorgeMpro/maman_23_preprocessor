#include <stdio.h>

/*todo extract*/
#define MAX_FILE_NAME 500
/*todo del*/
/*Print the name of the passed variable, its value and address in memory*/
#define PRINT_VAR(X)\
    printf(#X " is %d at address %p\n",X,&x);

int main() {

    /*todo del, examples from dani  *
    int x = 16961;
    printf("\n%d", x);
    putchar('\n');
    fwrite(&x, sizeof(int), 1, stdout);
*/
    int x;
    x = 1324;
    PRINT_VAR(x)
    return 0;
}
/*todo
 *          get arguments from user
 *          read file - from argv[1]
 *                  1. name can be 500 long
 *                  2. can include dots '.' before .c
 *                  3. start from the end, make sure it starts with c then . (going backwards)
 *          deal with error not reading
 *                  1. stderr or send error
 *          close and clear memory*/

/*todo
 * on valid file name
 * create new file with some suffix to write to*/

/*todo
 *          read include
 *          1. deal with normal #
 *          2. ignore spaces and tabs
 *          3. look for comments*/
/*TODO
 * first read only the file
 *          maybe r+/r go over the difference
 *          handle errors and exceptions
 *          Give information
 *          Note: windows/linux enter differenence - wds 2 bits(10 and 13), lnx 1 bit
 * process the file
 *          use the location to understand when start of comment
 *          when end of comment
 *          calc the distance and ignore it in writing the new file
 *                  1. single line comments
 *                  2. multi line comments
 *                  3. comments that are part of an existing line of text
 *          */

/*todo          when finding # and ** return a pointer to the location *
*          with fgetpos , fsetpos
*          remember when comment starts in mid sentence with location(do not read after
*          Maybe remember the distance from each point/from the begining with fseek
* alternatively, jum and ignore the comments - remember where they are and then jump over and write afterwards
*                  1. find start comment
*                  2. if whole line comment
*                  3. if multi line comment
*                  4. if comment as part of the text
*                  5. deal with printf("\n%d", x);
* */