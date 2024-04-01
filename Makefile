CC=gcc
CFLAGS=-I.
DEPS = extension.h
OBJ = main.o extension.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm -f $(OBJ) main
