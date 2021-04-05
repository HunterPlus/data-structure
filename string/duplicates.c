#include <stdio.h>

void duplicates (char *s)
{
    int h[128] = {0};
    
    for (; *s != '\0'; s++)
        h[*s]++;
    
    for (int i = 0; i < 128; i++)
        if (h[i] > 1)
            printf("%c: %d\n", i, h[i]);
}

int main()
{
    char *s = "Hello World! good good study, Day Dat up!";
    
    duplicates(s);

    return 0;
}
