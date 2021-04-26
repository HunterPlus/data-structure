#include <stdio.h>

int f(int n)
{
    if (n == 0 || n == 1)
        return 1;
    
    else
        return n * f(n - 1);
}
 
int main()
{
    int n = 5;
    printf("factorial of %d is: %d", n, f(n));
    return 0;
}
