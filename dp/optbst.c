#include <stdio.h>
#include <limits.h>

int optcost (int a[], int n)
{
    if (n == 0)
        return 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
        
    int min = INT_MAX;    
    for (int r = 0; r < n; r++)
    {
        int cost = optcost(a, r) + optcost(a+r+1, n-r-1);
        if(min > cost)
            min = cost;
    }
    return sum + min;
}

int main()
{
    int freq[] = {34, 8, 50};
    int n = sizeof(freq) / sizeof(freq[0]);
    
    printf("%d \n", optcost(freq, n));

    return 0;
}
