#include <stdio.h>
#include <stdlib.h>

int josephus (int n, int k)
{
    int i, idx;
    for (i = 1, idx = 0; i < n; i++)
        idx = (idx + k) % (i+1);
    return idx;
}
int Rjosephus (int n, int k)
{
    if (n == 1)
        return 0;
    int idx = (Rjosephus(n-1, k) + k) % n;
    return idx;
}

int Jose (int start, int m, int n)
{
    int i, size = n;
    int *jose =(int*)malloc(size * sizeof(int));
    
    for (i = 0; i < n; i++)
        jose[i] = i+1;
        
    int s = start % size;
    int t, j, x;
    while (size > 1)
    {
        t = (s + m - 1) % size;        
        x = jose[t];
        for (j = t; j < size-1; j++)
            jose[j] = jose[j+1];
        
        jose[j] = x;
        size--;
        s = t % size;
    }
    
    printf("Joseph cirle:\n");
    for (i = 0; i < n; i++)
        printf("%d ", jose[i]);
    
    printf("\n");
    
    x = jose[0];
    free (jose);
    
    return x;
}

int main()
{
    int start = 0;
    int m = 3;
    int n = 5;
    
    int x = Jose (start, m, n);
    printf("saver: %d\n", x);

    return 0;
}
