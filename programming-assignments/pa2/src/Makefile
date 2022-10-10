CC=gcc
CFLAGS=-I. -g -w
DEPS = find.h
OBJ = find.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

balance: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
