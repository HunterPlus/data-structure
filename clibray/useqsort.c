#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * qsort: sort a table of data.
 * #include <stdlib.h>
 * void qsort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));
 */

/* scmp: string compare of *s1 and *s2 */
int scmp(void *p1, void *p2)
{
	char	*s1, *s2;
	
	s1 = *(char **)p1;
	s2 = *(char **)p2;
	return strcmp(s1, s2);
}

int main()
{
	char	*str[N];	/* array [N] of pointers to string */
	
	qsort(str, N, sizeof(str[0]), scmp);
}
