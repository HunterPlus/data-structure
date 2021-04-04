#include <stdio.h>

void shellSort (int arr[], int n)
{
    int i, j, t, gap;
    
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            t = arr[i];
            
            for (j = i; j >= gap && arr[j-gap] > t; j -= gap )
                arr[j] = arr[j-gap];
            
            arr[j] = t;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 34, 54, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, n);
  
    shellSort(arr, n); 
    
    printArray(arr, n);

    return 0;
}
