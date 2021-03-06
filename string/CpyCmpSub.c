#include <stdio.h>
char *findFirst (char *s, char c);
char *findLast (char *s, char c);
char *stringcpy (char *dest, const char *src);
char *stringncpy(char *dest, const char *src, size_t count);
char *strcat(char *dest, const char *src);
int stringCmp (char *s1, char *s2);
int strcasecmp(const char *s1, const char *s2);
char *skipspaces(const char *s);
char *strim(char *s);

int strlength(char *s)
{
	char *sc;

	for (sc = s; *sc != '\0'; ++sc)
		/* nothing */;
	return sc - s;
}
char *findFirst (char *s, char c)
{
	while (*s && *s != (char)c)
		s++;
	return (char *)s;
}
char *findLast (char *s, char c)
{
	const char *last = NULL;
	do {
		if (*s == (char)c)
			last = s;
	} while (*s++);
	return (char *)last;
}

char *stringcpy (char *dest, const char *src)
{
	char *tmp = dest;

	while ((*dest++ = *src++) != '\0') ;
	
	return tmp;
}
char *stringncpy(char *dest, const char *src, size_t count)
{
	char *tmp = dest;

	while (count) {
		if ((*tmp = *src) != 0)
			src++;
		tmp++;
		count--;
	}
	return dest;
}
char *strcat(char *dest, const char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;
	while ((*dest++ = *src++) != '\0')
		;
	return tmp;
}

int stringCmp (char *s1, char *s2)
{
    while ((*s1 && *s2) && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    
    if (*s1 == *s2)
        return 0;
    else
        return (*s1 > *s2)? 1 : -1;
}

int strcasecmp(const char *s1, const char *s2)
{
	int c1, c2;

	do {
		c1 = tolower(*s1++);
		c2 = tolower(*s2++);
	} while (c1 == c2 && c1 != 0);
	return c1 - c2;
}
char *skipspaces(const char *s)
{
	while (isspace(*s))
		++s;
	return (char *)s;
}
char *strim(char *s)
{
	int size;
	char *end;

	size = strlength(s);
	if (!size)
		return s;

	end = s + size - 1;
	while (end >= s && isspace(*end))
		end--;
	*(end + 1) = '\0';

	return skipspaces(s);
}
int main()
{
    char *s2 = "Hello World!";
    
    char s1[15];
    
    cpyString(s1, s2);
    printf("%s\n", s1);

    return 0;
}
