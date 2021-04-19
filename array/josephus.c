#include <stdio.h>
int josephus (int n, int k)
{
    int i, idx;
    for (i = 1, idx = 0; i < n; i++)
        idx = (idx + k) % (i+1);
    return (idx + 1);
}
int main()
{
    int n = 14;
    int k = 2;
    
    printf("Josephus: %d\n", josephus(n, k));

    return 0;
}
