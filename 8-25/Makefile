BINARIES = main teacher-sol print-example char-io
C_FILES := $(addsuffix .c, ${BINARIES})

# `make` suffix rule for files with .c extension, use as: make main
.c:
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@

# `make` all files defined by FILES macro
all: $(C_FILES)
	make $(BINARIES)

# Remove all binaries created by `make`
clean:
	rm -rf $(BINARIES)