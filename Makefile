CN=class-notes
TB=textbook-notes
DIRS=$(CN)/8-25 $(CN)/8-30 $(TB)/ch1

.PHONY: all
all:
	$(foreach dir,$(DIRS), $(MAKE) --ignore-errors -C $(dir);)

.PHONY: $(DIRS)
$(DIRS): 
	$(MAKE) -C $@	

.PHONY: clean
clean:
	$(foreach dir,$(DIRS), $(MAKE) -C $(dir) clean;)