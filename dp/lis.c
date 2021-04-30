#include <stdio.h>
#include <limits.h>

int max (int a, int b) { return (a > b)? a : b; }

int lis (int a[], int n, int i, int prev)
{
    if (i == n)
        return 0;
        
    if (a[i] <= prev)
        return lis(a, n, i+1, prev);    
        
    return max(1 + lis(a, n, i+1, a[i]), lis(a, n, i+1, prev));
}

int main()
{
    int arr[] = {5, 11, 3, 15, 11, 25, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("LIS is : %d \n", lis(arr, n, 0, INT_MIN));

    return 0;
}
