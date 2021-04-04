#include <stdio.h>

void swap (int *a, int *b) {int t = *a; *a = *b; *b = t; }

void selectSort (int arr[], int n)
{
    int i, j, idx;
    
    for (i = 0; i < n-1; i++)
    {
        idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[idx])
                idx = j;
                
        swap(&arr[i], &arr[idx]);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
     printArray(arr, n);
     
    selectSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
