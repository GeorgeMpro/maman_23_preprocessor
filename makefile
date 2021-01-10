#todo update to fit the project
CC = gcc # compiler
CFLAGS = -ansi -Wall -pedantic # gcc flags
EXE_O_DEPS = preprocessor.o comment_remover.o file_setup_util.o# dependencies for executable

# final executable
preprocessor: $(EXE_O_DEPS)
	$(CC) -g $(EXE_O_DEPS) $(CFLAGS) -o $@

preprocessor.o: preprocessor.c
	$(CC) -c preprocessor.c $(CFLAGS) -o $@

comment_remover.o: comment_remover.c
	$(CC) -c comment_remover.c $(CFLAGS) -o $@

file_setup_util.o:file_setup_util.c
	$(CC) -c file_setup_util.c $(CFLAGS) -o $@
#todo reading

#todo writing

clean:
	rm *.o
