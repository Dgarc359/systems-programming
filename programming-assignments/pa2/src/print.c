#include "find.h"
void print_results(char* pattern, long flags, int no_of_results){
	char** sentences = (char**) malloc(no_of_results*sizeof(char*));
	for(int i = 0; i < no_of_results;i++){
		sentences[i] = strdup(lineptr[results[i]]);
	}
	if(flags & SORT){
		//call qsort on sentences...
	}else if (flags & REVERSE){
		//reverse the sentenes....
	}
	for(int i = 0; i < no_of_results;i++){
		if(flags & NUMBER)
			printf("numbered: %d. ", results[i] + 1); 
		if(flags & FIRST)
			if(flags & MATCH)
				printf("first match: @%d: ", strstr_fully_matched(sentences[i], pattern) - sentences[i]);
			else
				printf("first: @%d: ", strstr(sentences[i], pattern) - sentences[i]);
		printf("%s\n", sentences[i]);
	}
}