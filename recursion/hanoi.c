#include <stdio.h>

void Toh (int n, char A, char B, char C)
{
    static int count = 0;
    
    if (n > 0)
    {
        Toh(n-1, A, C, B);
        
        printf("No.%d: Moving #%d from %c to %c\n", ++count, n, A, C);
        
        Toh(n-1, B, A, C);
    }
}

int main()
{
    Toh(4, 'A', 'B', 'C');

    return 0;
}
