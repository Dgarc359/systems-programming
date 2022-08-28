DIRS=8-25
pwd=${PWD}

.PHONY: 8-25
$(DIRS): 
	cd $@ && make all

all:
	$(foreach dir,$(DIRS), cd $(dir) && make all && cd $(pwd);)

clean:
	$(foreach dir,$(DIRS), cd $(dir) && make clean && cd $(pwd);)