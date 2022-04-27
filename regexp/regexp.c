/* match:search for regexp anywhere in text */
int match(char *regexp, char *test)
{
	if (regexp[0] == '^)
	    return matchhere(regexp + 1, text);
	    
}
