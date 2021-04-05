#include <stdio.h>

int stringlength (char *s)
{
    int length;
    for (length = 0; s[length] != '\0'; length++) ;
    
    return length;
}

void reverseString (char* s)
{
    int size;
    for (size = 0; s[size]; size++) ;
    
    int i, j;
    char c;
    for (i=0,j=size-1; i < j; i++,j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    char s[] = "Algorithms";
    
    reverseString(s);
    
    printf("%s\n", s);
    
    for (int i = 0; i < 11; i++)
        printf("%d ", s[i]);
    
    return 0;
}

