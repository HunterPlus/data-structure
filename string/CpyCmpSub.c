#include <stdio.h>

char *findFirst (char *s, char c)
{
    for (; *s != c; s++)
        if (*s == '\0')
            return NULL;
        
    return s;
}
char *findLast (char *s, char c)
{
    char *sc;
    
    for (sc = NULL; ; s++)
    {
        if (*s == c)
            sc = s;
        
        if (*s == '\0')
            return sc;
    }
}
char *findSub (char *s1, char *s2)
{
    for (; (s1 = findFirst(s1, *s2)); s1++)
    {
        char *sc1, *sc2;
        
        for (sc1 = s1, sc2 = s2; ;)
        {
            if (*++sc2 == '\0')
                return s1;
            else if (*++sc1 != *sc2)
                break;
        }
    }
    
    return NULL;
}

int stringCmp (char *s1, char *s2)
{
    for (; (*s1 == *s2); s1++,s2++)
        if (*s1 == '\0')
            return 0;
            
    return (*s1 > *s2) ? 1 : -1;
}

char* cpyString (char *s1, char *s2)
{
    char *s;
    
    for (s = s1; (*s++ = *s2++); ) ;
    
    return s1;
}

int stringCmp1 (char *s1, char *s2)
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

int main()
{
    char *s2 = "Hello World!";
    
    char s1[15];
    
    cpyString(s1, s2);
    printf("%s\n", s1);

    return 0;
}
