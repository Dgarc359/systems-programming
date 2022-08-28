DIRS=8-25
pwd=${PWD}

$(DIRS):
	$(foreach dir,$(DIRS), $(MAKE) -C $@;)

.PHONY: $(DIRS)
$(DIRS): 
	$(MAKE) -C $@	

.PHONY: clean
clean:
	$(foreach dir,$(DIRS), $(MAKE) -C $(dir) clean;)