#include <stdio.h>

int min(int x, int y, int z) 
{
    int t = (x < y)? x : y;
    return (t < z)? t : z;
}

int editdist (char *s1, char *s2, int n1, int n2)
{
    if (n1 == 0)
        return n2;
    if (n2 == 0)
        return n1;
    if (s1[n1-1] == s2[n2-1])
        return editdist(s1, s2, n1-1, n2-1);
    else
        return 1 + min(editdist(s1, s2, n1, n2-1),
                        editdist(s1, s2, n1-1, n2),
                        editdist(s1, s2, n1-1, n2-1));
}

int main()
{
    int n1, n2;
    char* s1 = "sunday";
    char* s2 = "saturday";
    
    for (n1 = 0; s1[n1] != '\0'; n1++) ;
    for (n2 = 0; s2[n2] != '\0'; n2++) ;
    
    printf("%d\n", editdist(s1, s2, n1, n2));

    return 0;
}
