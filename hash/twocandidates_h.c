#include <stdio.h>
#define MAX 100000

void twocandidates (int arr[], int n, int sum)
{
    int i, tmp;
    int ht[MAX] = { 0 };
    
    for (i = 0; i < n; i++)
    {
        tmp = sum - arr[i];
        if (ht[tmp] == 1)
            printf("two candidates for sum %d is: (%d, %d).\n", 
                    sum, arr[i], tmp);
        ht[arr[i]] = 1;
    }
}

int main()
{
    int a[] = { 1, 4, 45, -3, 10, 8 };
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 14;
 
    twocandidates(a, n, sum);

    return 0;
}
