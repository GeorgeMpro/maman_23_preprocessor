#include <stdio.h>
#include "header1.h"/*Comment*/
#include          /*Comment*/       "header2.h"

#  include  "header3.h"

#define DEF 1
#define ABC "Hello"
#define PRINT_VAR(X) printf(#X " is %d at address %p\n",X,&x);

int main() {
    int x; /*comment*/
    char /*comment*/ a;
    a = 'a';

    /*Multi
     * line
     * comment*/
    x = 123;/*the 123 value*/
    printf("/*not a comment*/");
    printf("\nx is: %d. a is %c", x, a);

#include "another.h"

    printf("%s World!", ABC);

    return 0;
}