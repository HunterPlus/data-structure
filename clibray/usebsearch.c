#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(array)	(sizeof(array) / sizeof(array[0]))

/*
 * bsearch: binary search of a sorted array
 * #include <stdlib.h>
 * void *bsearch(cost void *key, const void *base, 
 		size_t nmemb, size_t size, 
		int (*compar)(const void *, const void *));
 * nmemb: number of objects in the array.
 * size: the size of each member of the array.
 * return value: a pointer to the matching memeber, or NULL if not found.
 */

struct key {
	char	*word;
	int	count;
} keytab[] = {
	"auto", 	0,
	"break", 	0,
	"case", 	0,
	"char", 	0,
	"const",	0,
	"continue",	0,
	"default",	0,
	/* ... */
	"unsigned",	0,
	"void",		0,
	"volatile",	0,
	"while",	0
};

/* keycmp: compare two word of struct key */
int keycmp(const void *va, const void *vb)
{
	const struct key *a, *b;
	
	a = (struct key *) va;
	b = (struct key *) vb;
	return strcmp(a->word, b->word);
}

/* lookup(): using bsearch() to find key in keytab[]
 * return index in keytab, or -1 if not found.
 */
int lookup(char *word, struct key tab[], int ntab)
{
	struct key key, *kp;
	
	key.word = word;
	key.count = 0;		/* unused, anything will do */
	kp = bsearch(&key, tab, ntab, sizeof(tab[0]), keycmp);
	if (kp == NULL)
		return -1;
	return (kp - tab);
}

int main()
{
	int	i;
	char	*keyword = "void";
	
	if ((i = lookup(keyword, keytab, NELEMS(keytab))) == -1)
		printf("keyword %s was not found in keytab.\n", keyword);
	else
		printf ("keyword %s at index of: %d\n", keyword, i);
	return 0;
}
