#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * qsort: sort a table of data.
 * #include <stdlib.h>
 * void qsort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));
 */

/* scmp: string compare of *p1 and *p2 */
int scmp(void *p1, void *p2)
{
	char	*s1, *s2;
	
	s1 = *(char **)p1;
	s2 = *(char **)p2;
	return strcmp(s1, s2);
}

/* icmp: integer compare of *p1 and *p2	*/
int icmp(void *p1, void *p2)
{
	int	v1, v2;
	
	v1 = *(int *)p1;
	v2 = *(int *)p2;
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	return 0;
}

int main()
{
	char	*str[N];	/* array [N] of pointers to string */
	int	arr[N];
	
	qsort(str, N, sizeof(str[0]), scmp);
	qsort(arr, N, sizeof(arr[0]), icmp);
}
