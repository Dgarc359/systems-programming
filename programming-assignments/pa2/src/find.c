#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "find.h"
char** lineptr; // externally defined because they're defined before main

/**
 * Track index of stdin arr of strings to print
 */
int results[MAX_LINE];
int readlines(char *lineptr[], int nlines);

/**
 * check if needle is a substr of haystack, including checking for padding
 * @param haystack
 * @param needle
 * @return
 */
char* strstr_fully_matched(char* haystack, char* needle) {
	char* rv;
	char* padded_needle[strlen(needle) + 3];
	padded_needle[0] = ' ';
	strcpy(padded_needle + 1, needle);
	padded_needle[strlen(needle) + 1] = ' ';
	padded_needle[strlen(needle) + 2] = '\0';
	if(strncmp(haystack, padded_needle + 1, strlen(needle) + 1))
	return haystack; // needle at the beginning
	if((rv = strstr(haystack, padded_needle)) != NULL)
	return rv + 1; // needle is in the middle
	padded_needle[strlen(needle) + 1] = '\0';
	if((rv = strstr(haystack, padded_needle)) != NULL)
	return rv + 1; // needle is at the end
}

int get_line(char line[], int max);

int main(int argc, char** argv) {
	char* line[MAX_LINE];
	long lineno = 0;

	char* pattern;

	int found = 0;

	/**
	 * Read user flags
	 */
	int c = 0;

	/**
	 * 8 vals in cla_flags enum
	 */
	long flags;
	if (argc == 0) return 0;
	printf("> reading user flags...\n");
	while(--argc > 0 && (*++argv)) {
		while ((c = *++argv[0])) {
			switch(c) {
				case 'n':
					flags |= NUMBER;
				case 'x': // TODO: f and x cannot be combined
					flags |= EXCLUDE;
				case 's': // TODO: s and r cannot be combined
					flags |= SORT;
				case 'r': // TODO: s and r cannot be combined
					flags |= REVERSE;
				case 'm':
					flags |= MATCH;
				case 'c':
					flags |= CASE;
				case 'f': // TODO: f and x cannot be combined
					flags |= FIRST;
				case 'p':
					flags |= PARTIAL;
			}
		}
	}

	int nlines = readlines(line, MAX_LINE); // this function will populate lineptr[] arr
	printf("lines: %s", line[0]);
	printf("nlines: %d\n", nlines);
	int no_of_results = 0;
	for(int i = 0; i< nlines; i++) {
	if(flags & MATCH){
		if((strstr_fully_matched(line[i], pattern) != NULL) != (flags & EXCLUDE))
			results[no_of_results++] = i;
	} else {
			printf("in else\n");
			if((strstr(line[i], pattern) != NULL) != ( flags & EXCLUDE))
				results[no_of_results++] = i;
		}
	}
	printf("\n>printing results\n");
	printf("# of results: %d\n", no_of_results);
	print_results(pattern, flags, no_of_results, results);
	return 0;
}

/**
 * uses getchar() to get string from stdin
 * @param s
 * @param lim
 * @return
 */
int get_line(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	s[i] = c;
	if (c == '\n') {
	s[i] = c;
	i++;
	}
	s[i] = '\0';
	return i;
}

// read input lines
int readlines(char* lineptr[], int maxlines) {
	int len;
	int nlines;

	char* p;
	char* line[MAX_LINE];

	nlines = 0;

	printf("\nreading lines\n");
	while((len = get_line(line, MAX_LINE)) > 0)
	if (nlines >= maxlines || (p = alloc(len)) == NULL){
		return -1;
	}
	else {
		line[len - 1] = '\0'; // del \n
		strcpy(p, line);
		printf("p: %s", p);
		lineptr[nlines++] = p;
	}
	return nlines;
}
