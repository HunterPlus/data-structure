#include <stdio.h>
#include <limits.h>

int mco(int p[], int n)
{
    int m[n][n];

    int i, j, k, L, q;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            m[i][j] = 0;
   
    for (L = 2; L < n; L++)
    {
        for (i = 1; i <= n - L; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t\t", m[i][j]);

        printf("\n");
    }
    return m[1][n - 1];
}

int main()
{
    int arr[] = {8, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d ",
           mco(arr, size));

    return 0;
}
