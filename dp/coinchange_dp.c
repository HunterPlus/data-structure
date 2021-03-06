#include <stdio.h>

int count (int S[], int n, int m)
{
    int i, j, x, y;
    
    int table[n+1][m];
    
    for (j = 0; j < m; j++)
        table[0][j] = 1;
    
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = ((i - S[j]) >= 0)? table[i-S[j]][j] : 0;
            
            y = (j >= 1)? table[i][j-1] : 0;
            
            table[i][j] = x + y;
        }
    }
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d ",table[i][j]);
        printf("\n");
    }
    return table[n][m-1];
}

int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    printf(" %d ", count(arr, n, m));

    return 0;
}
