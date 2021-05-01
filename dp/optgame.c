#include <stdio.h>

int max (int a, int b) { return (a > b)? a : b; }
int min (int a, int b) { return (a < b)? a : b; }

int findopt (int val[], int i, int j)
{
    if (i == j)
        return val[i];
    if (j == i+1)
        return max(val[i], val[j]);
    return max(val[i] + min(findopt(val, i+2, j), findopt(val, i+1, j-1)),
            val[j] + min(findopt(val, i, j-2), findopt(val, i+1, j-1)));
}

int main()
{
    int arr1[] = { 8, 15, 3, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n",
           findopt(arr1, 0, n-1));
 
    int arr2[] = { 2, 2, 2, 2 };
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n",
           findopt(arr2, 0, n-1));
 
    int arr3[] = { 20, 30, 2, 2, 2, 10 };
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n",
           findopt(arr3, 0, n-1));

    return 0;
}
