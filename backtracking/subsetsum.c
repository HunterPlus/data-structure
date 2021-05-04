#include <stdio.h>

void printarray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void subsetsum (int set[], int t[], int n, int sum, int count)
{
    if (sum == 0) 
    {
        printarray(t, count);
        return;
    }
    if (sum < 0 || n == 0)
        return;

    t[count] =set[0];    
    subsetsum(set+1, t, n-1, sum-set[0], count+1);
    
    subsetsum(set+1, t, n-1, sum, count);
    
    return;
}
void findsubset (int set[], int n, int sum)
{
   int t[n];
   
   subsetsum(set, t, n, sum, 0);
}

int main()
{
    int arr[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int sum = 35;
    
    findsubset(arr, n, sum);

    return 0;
}
