TB=textbook-notes
DIRS=8-25 $(TB)/ch1

.PHONY: all
all:
	$(foreach dir,$(DIRS), $(MAKE) --ignore-errors -C $(dir);)

.PHONY: $(DIRS)
$(DIRS): 
	$(MAKE) -C $@	

.PHONY: clean
clean:
	$(foreach dir,$(DIRS), $(MAKE) -C $(dir) clean;)