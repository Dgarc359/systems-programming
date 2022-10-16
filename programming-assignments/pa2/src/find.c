#include"find.h"
#define MAX_LINES 1000
#define MAX_LEN 1000
char*lineptr[MAX_LINES];
int results[MAX_LINES];

char* str_tolower(char* input){
	char* rv = strdup(input);
	for(int i = 0; i < strlen(rv);i++)
		rv[i] = tolower(rv[i]);
	return rv;
}

/**
 * check if needle is a substr of haystack, including checking for padding
 * @param haystack
 * @param needle
 * @return
 */

 char *strstr_fully_matched(char *haystack, char *needle) {
	 char *rv;
	 char padded_needle[strlen(needle) + 3];
	 padded_needle[0] = ' ';
	 strcpy(padded_needle + 1, needle);
	 padded_needle[strlen(needle) + 1] = ' ';
	 padded_needle[strlen(needle) + 2] = '\0';
	 if (!strncmp(haystack, padded_needle + 1, strlen(needle) + 1)) {
		 return haystack; // needle is at the beginning
	 }
	 if ((rv = strstr(haystack, padded_needle)) != NULL) {
		 return rv + 1; // needle is at the middle.
	 }
	 padded_needle[strlen(needle) + 1] = '\0';
	 if ((rv = strstr(haystack, padded_needle)) != NULL && rv[strlen(padded_needle)] == '\0') {
			return rv + 1; // needle is at the end.
	 }
	 return NULL;
 }


int getline2(char s[], int lim){
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n';i++)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}
int readlines(char** lineptr, int maxlines){
	int len, nlines;
	char*p, line[MAX_LEN];
	
	nlines = 0;
	while((len = getline2(line, MAX_LEN)) > 0)
		if(nlines >= maxlines || (p = malloc(len)) == NULL)
			return -1;
		else{
			if(line[len - 1] == '\n')
				line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}
int main(int argc, char** argv)
{
	int flags;
	char* pattern = "in";
	int c = 0;
	//....
	//handle command line arguments...
	while(--argc > 0 && (*++argv)) {
		while ((c = *++argv[0])) {
			// printf("%c", c);
			switch(c) {
				case 'n':
					flags |= NUMBER;
					break;
				case 'x': // TODO: f and x cannot be combined
					flags |= EXCLUDE;
					break;
				case 's': // TODO: s and r cannot be combined
					flags |= SORT;
					break;
				case 'r': // TODO: s and r cannot be combined
					flags |= REVERSE;
					break;
				case 'm':
					flags |= MATCH;
					break;
				case 'c':
					flags |= CASE;
					break;
				case 'f': // TODO: f and x cannot be combined
					flags |= FIRST;
					break;
				case 'p':
					flags |= PARTIAL;
					break;
			}
		}
	}
	//similar to #41 of Chapter 5 partII.pptx
	int nlines = readlines(lineptr, MAX_LINES);//similar, but not the same as the slide #23 of Chapter 5 partII.pptx
	int no_of_results = 0;
	for(int i = 0; i < nlines;i++){
		if((flags & MATCH)){
			printf("matching??");
			if((strstr_fully_matched(lineptr[i], pattern) != NULL) != (flags & EXCLUDE))
				results[no_of_results++] = i;
		}else{
			printf("inside else\n");
			if((strstr(lineptr[i], pattern) != NULL) != (flags & EXCLUDE))
				results[no_of_results++] = i;
		}
	}
	print_results(pattern, flags, no_of_results);
	return 0;
}