CC=gcc
CFLAGS=-I.
DEPS = hellomake.h

# You can slap this block into every program for the class and it will work
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.o hellofunc.o 
	$(CC) -o hellomake hellomake.o hellofunc.o 
