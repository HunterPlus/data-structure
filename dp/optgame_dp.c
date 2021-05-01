#include <stdio.h>
int max (int a, int b) { return (a > b)? a : b; }
int min (int a, int b) { return (a < b)? a : b; }

int findopt (int val[], int n, int i, int j, int *dp)
{
    if (i == j)
        return val[i];
    if (j == i+1)
        return max(val[i], val[j]);
        
    if (dp[n*i + j] != -1)
        return dp[n*i + j];
     
    int x, y;
    
    x = min(findopt(val, n, i+2, j, dp), findopt(val, n, i+1, j-1, dp));
    x += val[i];
    
    y = min(findopt(val, n, i, j-2, dp), findopt(val, n, i+1, j-1, dp));
    y += val[j];
    
    return dp[n*i + j] = max(x, y);
}
int optgame (int val[], int n)
{
    int dp[n * n];
    for (int i = 0; i < n*n; i++)
        dp[i] = -1;
        
    int opt = findopt(val, n, 0, n-1, dp);
    return opt;
}

int main()
{
    int arr1[] = { 8, 15, 3, 7, 10 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optgame(arr1, n));
 
    int arr2[] = { 2, 2, 2, 2 };
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optgame(arr2, n));
 
    int arr3[] = { 20, 30, 2, 2, 2, 10 };
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optgame(arr3, n));

    return 0;
}
