#include <stdio.h>

int subsetsum(int set[], int n, int sum)
{
    int subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        subset[i][0] = 1;
    for (int j = 0; j <= sum; j++)
        subset[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            else
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (subsetsum(set, n, sum) == 1)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");

    return 0;
}
