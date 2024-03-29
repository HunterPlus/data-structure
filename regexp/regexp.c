#include <stdio.h>
#include <stdlib.h>

/*
 * 	c	matches any literal character c
 * 	.	matches any single character
 * 	^    	matches the beginning of the input string
 * 	$    	matches the end of the input string
 * 	*    	matches zero or more occurrences of the previous character
 */

int matchhere(char *, char *);
int matchstar(int, char *, char *);
int matchstar1(int, char *, char *);	/* leftmost longest match */

/* match:search for regexp anywhere in text */
int match(char *regexp, char *text)
{
	if (regexp[0] == '^')
		return matchhere(regexp + 1, text);
	do {		/* must look even string is empty	*/
		if (matchhere(regexp, text))
			return 1;
	} while (*text++ != '\0');
	return 0;
}

/*  matchhere: search for regexp at beginning of text */
int matchhere(char *regexp, char *text)
{
	if (regexp[0] == '\0')
		return 1;
	if (regexp[1] == '*')
		return matchstar(regexp[0], regexp + 2, text);
	if (regexp[0] == '$' && regexp[1] == '\0')
		return *text == '\0';
	if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
		return matchhere(regexp + 1, text + 1);
	return 0;		
}

/* matchstar: search for c*regexp at beginning of the text */
int matchstar(int c, char *regexp, char *text)
{
	do {		/* a * matches zero or more instance */
		if (matchhere(regexp, text))
			return 1;
	} while (*text != '\0' && (*text++ == c || c == '.'));
	return 0;
}

/* 
 * matchstar1: identifying a maximal sequence of occurrences of 
 * the input character c. Then uses matchhere to try to extend 
 * the match to the rest of the pattern and the rest of the text. 
 */
int matchstar1(int c, char *regexp, char *text)
{
	char	*t;
	
	for (t = text; *t != '\0' && (*t == c || c == '.'); t++)
		;
	do {		/* match zero or more */
		if (matchhere(regexp, t))
			return 1;
	} while (t-- > text);
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage: match <regexp> <text>");
		exit(1);
	}
	if(match(argv[1], argv[2]))
		printf("match found.\n");
	else
		printf("no match.\n");
	return 0;
}
