/*todo clean*/
/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include "file_setup_util.h"

/*Definitions*/
#define INSERTED_CONTENT_SUFFIX '2'

#define BUFFER_MAX_SIZE 500

/*Functions*/
void insert_includes(FILE *in, FILE *out);

void generate_file_with_written_libraries(FILE *in, char *name);