#include <stdio.h>
#include <stdlib.h>

int Jose (int start, int m, int n)
{
    int size = n;
    int *jose =(int*)malloc(size * sizeof(int));
    
    for (int i = 0; i < n; i++)
        jose[i] = i+1;
        
    int s = start % size;
    int t, j;
    while (size > 1)
    {
        t = (s + m - 1) % size;
        printf("remove: %d \n", jose[t]);
   
        for (j = t; j < size-1; j++)
            jose[j] = jose[j+1];
        
        size--;
        s = t % size;
    }
    
    int x = jose[0];
    
    free (jose);
    
    return x;
}

int main()
{
    int start = 1;
    int m = 1;
    int n = 2;
    
    int x = Jose (start, m, n);
    
    printf("saver: %d", x);

    return 0;
}
