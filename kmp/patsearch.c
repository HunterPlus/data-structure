#include <stdio.h>
#include <string.h>

int patcmp(char *s, char *pat, int n)
{
	char *s1, *pat1;
	int res = 0;

	for (s1 = s, pat1 = pat; n > 0; ++s1, ++pat1, n--)
		if ((res = *s1 - *pat1) != 0)
			break;
	return res;
}
int patsearch(char *s, char *pat)
{
	int l1, l2;

	l1 = strlen(s);
	l2 = strlen(pat);
    char *s1 = s;
	while (l1 >= l2) {		
		if (!patcmp(s1, pat, l2))
			return (s1 - s);
        
        l1--;
		s1++;
	}
	return -1;
}
