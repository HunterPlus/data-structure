#include <stdio.h>

int subsum (int s[], int t[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0 || n == 0)
        return 0;
    
    if (subsum(s, t, n-1, sum-s[n-1]))
    {
        t[n-1] = s[n-1];
        return 1;
    }
    if (subsum(s, t, n-1, sum))
        return 1;    
    
    return 0;
}
void subsetsum (int s[], int n, int sum)
{
    int t[n];
    for (int i = 0; i < n; i++)
        t[i] = 0;
    
    if (subsum(s, t, n, sum))
        for (int i = 0; i < n; i++)
            printf("%2d ", t[i]);
    else
        printf("There is no solution on this sum");
}

int main()
{
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 45;
    
    subsetsum(set, n, sum);

    return 0;
}
