#include <stdio.h>

int lis (int a[], int n)
{
    int max = 1, end = 0;
    int dp[n];

    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        
        if (dp[i] > max)
            end = i, max = dp[i];
    }

    for (int i = 0; i < n; i++)
        printf("%2d ", dp[i]);

    printf("\nidx end: %d\tLIS: %d ", end, max);

    return max;
}

int main()
{
    int arr[] = {5, 11, 3, 15, 11, 25, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    lis(arr, n);

    return 0;
}
