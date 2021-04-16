#include <stdio.h>
#include <stdlib.h>

int min (int x, int y) { return (x < y)? x : y;}

int minrec(int arr[], int i, int s1, int s)
{
    if (i ==0)
        return abs((s - s1) - s1);
    
    return min(minrec(arr, i-1, s1+arr[i-1], s),
                minrec(arr, i-1, s1, s));
}
int findmin (int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += arr[i];
    return minrec(arr, n, 0, s);
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("%d\n", findmin(arr, n));

    return 0;
}
