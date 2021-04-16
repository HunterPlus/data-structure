#include <stdio.h>

int countdp (int dist)
{
    int count[dist + 1];
    
    count[0] = 1;
    if (dist >= 1)
        count[1] = 1;
    if (dist >= 2)
        count[2] = 2;
    
    for (int i = 3; i <= dist; i++)
        count[i] = count[i-1] + count[i-2] + count[i-3];
        
    for (int i = 0; i <= dist; i++)
        printf("%d ", count[i]);
        
    return count[dist];
}

int main()
{
    int distance = 4;
    
    printf("\n%d\n", countdp(distance));

    return 0;
}
