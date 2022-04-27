/* match:search for regexp anywhere in text */
int match(char *regexp, char *test)
{
	if (regexp[0] == '^')
		return matchhere(regexp + 1, text);
	do {		/* must look even string is empty	*/
		if (matchhere(regexp, text))
	}
}
