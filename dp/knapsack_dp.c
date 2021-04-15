#include <stdio.h>

int max(int a, int b) { return (a > b)? a : b; }

int knapsack(int vt[], int wt[], int n, int w)
{
    int i, j;
    int k[n+1][w+1];
    
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                k[i][j] = 0;
            else if (wt[i-1] <= j)
                k[i][j] = max(vt[i-1] + k[i-1][j-wt[i-1]], k[i-1][j]);
            else
                k[i][j] = k[i-1][j];
        }
    }
    printf("Knapsack Dynamic table:\n");
    for (int i = 0; i <= n; i++)
    {
        for (j = 0; j <= w; j++)
            printf("%d  ", k[i][j]);
        
        printf("\n");
    }    
    return k[n][w];
}

int main()
{
    int vt[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int w = 50;
    int n = sizeof(vt) / sizeof(vt[0]);
    printf("%d", knapsack(vt, wt, n, w));

    return 0;
}

