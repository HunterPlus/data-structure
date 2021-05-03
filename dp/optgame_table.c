#include <stdio.h>

int min(int a, int b) { return (a < b) ? a : b; }

int optgame(int coins[], int n)
{
    int dp[n][n];
    int i, j, L;
 
    for (j = 0; j < n; j++)
        dp[j][j] = coins[j];

    for (L = 2; L <= n; L++)
    {
        for (i = 0; i <= n - L; i++)
        {
            j = i + L - 1;

            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += coins[k];

            int x = min(dp[i + 1][j], dp[i][j - 1]);
            dp[i][j] = sum - x;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optgame(arr1, n));

    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optgame(arr2, n));

    int arr3[] = {20, 30, 2, 2, 2, 10};
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optgame(arr3, n));

    return 0;
}
