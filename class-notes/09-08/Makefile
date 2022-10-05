BINARIES = class-activity
C_FILES := $(addsuffix .c, ${BINARIES})

# `make` all files defined by C_FILES macro
all: $(C_FILES)
	make $(BINARIES)

# `make` suffix rule for files with .c extension, use as: make main
.c:
	$(CC) $(CFLAGS) $@.c $(LDFLAGS) -o $@

.PHONY: clean
# Remove all binaries created by `make`
clean:
	rm -rf $(BINARIES)
