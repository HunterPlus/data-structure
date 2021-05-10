#include <stdio.h>

void printarray (int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void swap (int *x, int *y) { int t = *x; *x = *y; *y = t; }

void permuteutil (int a[], int buff[], int n, int idx)
{
    if (n == 1)
    {
        buff[idx] = a[0];
        printarray(buff, idx+1);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        swap(a, a + i);
        buff[idx] = a[0];
        permuteutil(a+1, buff, n-1, idx+1);
        
        swap(a, a + i);
    }
}

void permute (int a[], int n)
{
    int buff[n];
    
    permuteutil(a, buff, n, 0);
}
int main()
{
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    
    permute(a, n);

    return 0;
}
