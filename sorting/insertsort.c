#include <stdio.h>

void swap (int *x, int *y) { int t = *x; *x = *y; *y = t; }
void insertsort1(int v[], int n)
{
    int i, j, idx;
    
    for (i = 0; i < n; i++) {
        idx = i;
        for (j = i; j < n; j++)
            if (v[j]< v[idx])
                idx = j;
        swap(v + i, v + idx);
    }
}
void insertSort (int arr[], int n)
{
    int i, j, key;
    
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        
        while (j >=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertSort(arr, n);
    printArray(arr, n);

    return 0;
}
