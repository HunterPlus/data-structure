#include <stdio.h>
#include <limits.h>

int mco (int p[], int i, int j)
{
    if (i == j)
        return 0;
        
    int min = INT_MAX;
    int count;
    
    for (int k = i; k < j; k++)
    {
        count = mco(p, i, k) +
                    mco(p, k+1, j) +
                        p[i-1] * p[k] * p[j];
        if (count < min)
            min = count;
    }
    return min;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("Minimum number of multiplications is %d ",
           mco(arr, 1, n - 1));

    return 0;
}
