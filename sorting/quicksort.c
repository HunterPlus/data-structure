#include <stdio.h>

void swap (int *a, int *b) {int t = *a; *a = *b; *b = t; }

int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = l - 1;
    
    for (int j = l; j <= h-1; j++)
        if (arr[j] <= x)
            swap(&arr[++i], &arr[j]);
    
    swap(&arr[++i], &arr[h]);
    
    return i;
}

void quickSort (int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }
}

int main()
{
    int arr[] = { 4, 2, 6, 9, 2 };
    
    int n = sizeof(arr) / sizeof(arr[0]);
  
    quickSort(arr, 0, n - 1);
  
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
 
    return 0;
}
