#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
/*TODO
 * first read only the file
 *          maybe r+/r go over the difference
 *          handle errors and exceptions
 *          Give information
 *          Note: windows/linux enter differenence - wds 2 bits(10 and 13), lnx 1 bit
 * process the file
 *          when finding # and ** return a pointer to the location *
 *          with fgetpos , fsetpos
 *          remember when comment starts in mid sentence with location(do not read after
 *          Maybe remember the distance from each point/from the begining with fseek
 * alternatively, jum and ignore the comments - remember where they are and then jump over and write afterwards
 *                  1. find start comment
 *                  2. if whole line comment
 *                  3. if multi line comment
 *                  4. if comment as part of the text
 * */