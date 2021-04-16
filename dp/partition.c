#include <stdio.h>

int ispartition (int arr[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0 && sum != 0)
        return 0;
    if (arr[n-1] > sum)
        return ispartition(arr, n-1, sum);
    
    return ispartition(arr, n-1, sum-arr[n-1])
            || ispartition(arr, n-1, sum);
}
int findpartition (int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    if (sum % 2 != 0)
        return 0;
        
    return ispartition(arr, n, sum/2);
}

int main()
{
    int arr[] = { 3, 1, 5, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    if (findpartition(arr, n))
        printf("Can be divided into two subsets "
               "of equal sum");
    else
        printf("Can not be divided into two subsets"
               " of equal sum");

    return 0;
}
