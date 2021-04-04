#include <stdio.h>

void countSort (int arr[], int n)
{
    int count[10] = {0};
    int output[n];
    
    int i;
    for (i = 0; i < n; i++)
        count[arr[i]]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
    for (i = n-1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

int main()
{
    int a[] = {3, 7, 5, 2, 8, 7, 2, 6, 7, 3, 0, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    printArray(a, n);
    
    countSort(a, n);
    printArray(a, n);
    
    return 0;
}
