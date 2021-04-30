#include <stdio.h>
#include <limits.h>

int max (int a, int b) { return (a > b)? a : b; }

int cutRod (int p[], int n)
{
    int v[n + 1];
    v[0] = 0;
    for (int L = 1; L <= n; L++)
    {
        int q = INT_MIN;
        for (int i = 0; i < L; i++){
            q = max(q, p[i] + v[L-i-1]);
            v[L] = q;
        }
    }
    return v[n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));

    return 0;
}
