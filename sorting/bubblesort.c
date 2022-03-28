#include <stdio.h>
void bubble(int v[], int n)
{
    int i, idx;
    int temp;
    
    for (; n > 1; n--) {
        idx = 0;
        for (i = 0; i < n; i++)
            if (v[i] > v[idx])
                idx = i;
        temp = v[n-1];
        v[n-1] = v[idx];
        v[idx] = temp;
    }
}
void swap (int *x, int *y) { int t = *x; *x = *y; *y = t; }

void bubbleSort (int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
