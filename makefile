#todo update to fit the project
CC = gcc # compiler
CFLAGS = -ansi -Wall -pedantic # gcc flags
EXE_O_DEPS = preprocessor.o mat.o mat_setup_teardown.o input.o command_util.o # dependencies for executable

# final executable
preprocessor: $(EXE_O_DEPS)
	$(CC) -g $(EXE_O_DEPS) $(CFLAGS) -o $@

preprocessor.o: preprocessor.c
	$(CC) -c preprocessor.c $(CFLAGS) -o $@
#todo reading

#todo writing

clean:
	rm *.o
