#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
       s += freq[k];
    return s;
}
int optcost (int a[], int n)
{
    int cost[n][n];
    for (int i = 0; i <= n; i++)
        cost[i][i] = a[i];
        
    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i <= n-L; i++)
        {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            int s = sum(a, i, j);
            
            for (int r = i; r <= j; r++)
            {
                int c = ((r > i)? cost[i][r-1] : 0) +
                        ((r < j)? cost[r+1][j] : 0) + s;
                
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", cost[i][j]);
        printf("\n");
    }
    return cost[0][n-1];
}

int main()
{
    int freq[] = {34, 8, 50};
    int n = sizeof(freq) / sizeof(freq[0]);
    
    optcost(freq, n);

    return 0;
}
