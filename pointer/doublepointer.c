#include <stdio.h>

int main()
{
    int var = 56;
    
    int *p1;
    int **p2;
    
    p1 = &var;
    p2 = &p1;

    printf("var = %d\n", var );
    printf("var using single pointer = %d, address = %p\n", *p1, p1 );
    printf("var using double pointer = %d, pointer = %p\n", **p2, *p2);
    
    return 0;
}
