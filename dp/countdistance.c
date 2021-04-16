#include <stdio.h>

int countrec (int dist)
{
    if (dist < 0)
        return 0;
    if (dist == 0)
        return 1;

    return countrec(dist - 1) + countrec(dist - 2) + countrec(dist - 3);
}

int main()
{
    int distance = 4;
    
    printf("%d\n", countrec(distance));

    return 0;
}
