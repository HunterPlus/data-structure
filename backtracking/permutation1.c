#include <stdio.h>

void printarray (int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void swap (int *x, int *y) { int t = *x; *x = *y; *y = t; }

void permute (int a[], int l, int r)
{
    if (l == r)
    {
        printarray(a, r+1);
        return;
    }
        
    for (int i = l; i <= r; i++)
    {
        swap(a+l, a+i);
        
        permute(a, l+1, r);
        
        swap(a+l, a+i);
    }

}
int main()
{
    int a[] = {1, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    
    permute(a, 0, n-1);

    return 0;
}
