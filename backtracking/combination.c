#include <stdio.h>

void printarray (int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void combinutil (int a[], int n, int buff[], int counter, int r)
{
    if (counter == r)
    {
        printarray(buff, counter);
        return;
    }
    if (n == 0)
        return;
        
    buff[counter] = a[0];
    combinutil(a+1, n-1, buff, counter+1, r);
        
    combinutil(a+1, n-1, buff, counter, r);
}

void combination (int a[], int n, int r)
{
    int buff[r];
    
    combinutil(a, n, buff, 0, r);
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    
    combination(a, n, 3);

    return 0;
}
