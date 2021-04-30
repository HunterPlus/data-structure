#include <stdio.h>

int lis (int a[], int n)
{
    int dp[n];
    
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[j] + 1 > dp[i])
            dp[i] = dp[j] + 1;
        }
    }
    int max = dp[0];
    for (int i = 0; i < n; i++)
        max = (dp[i] > max)? dp[i] : max;

    return max;
}

int main()
{
    int arr[] = {5, 11, 3, 15, 11, 25, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("\nLIS is : %d \n", lis(arr, n));

    return 0;
}
