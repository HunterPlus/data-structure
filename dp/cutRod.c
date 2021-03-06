#include <stdio.h>
#include <limits.h>

int max (int a, int b) { return (a > b)? a : b; }

int cutRod (int p[], int n)
{
    if (n <= 0)
        return 0;
    
    int q = INT_MIN;
    for (int i = 0; i < n; i++)
        q = max(q, p[i] + cutRod(p, n-i-1));
    
    return q;
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));

    return 0;
}
