#include <stdio.h>

int issubsetsum (int set[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    
    if (sum < set[n - 1])
        return issubsetsum(set, n-1, sum);
        
    return issubsetsum(set, n-1, sum) ||
            issubsetsum(set, n-1, sum - set[n-1]);
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (issubsetsum(set, n, sum) == 1)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");

    return 0;
}
