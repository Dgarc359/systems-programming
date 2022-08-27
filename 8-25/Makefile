FILES = main teacher-sol print-example char-io

# `make` any single file, example: make main.c
.c:
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@

# `make` all files defined by FILES macro
all:
	make $(FILES)

# Remove all binaries created by `make`
clean:
	rm -rf $(FILES)