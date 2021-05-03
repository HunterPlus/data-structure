#include <stdio.h>

int max (int a, int b) { return (a > b)? a : b; }
int min (int a, int b) { return (a < b)? a : b; }

int findopt (int val[], int i, int j, int sum)
{
    if (i == j)
        return val[i];    
    if (j == i+1)
        return max(val[i], val[j]);
    return sum - min(findopt(val, i+1, j, sum-val[i]),
                    findopt(val, i, j-1, sum-val[j]));
}
int optgame (int val[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += val[i];
    
    return findopt(val, 0, n-1, sum);
}

int main()
{
    int arr1[] = { 8, 15, 3, 7 };
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
