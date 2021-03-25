#include <stdio.h>

void swap (int *x, int *y) {int t = *x; *x = *y; *y = t; }

void maxHeap (int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[(i-1) / 2])
        {
            int j = i;
            while (arr[j] > arr[(j-1) / 2])
            {
                swap(&arr[j], &arr[(j-1) / 2]);
                j = (j-1) / 2;
            }
        }
    }
}
void heapSort (int arr[], int n)
{
    maxHeap(arr, n);
    
    for (int i = n-1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        
        int j = 0, idx;
        do
        {
            idx = 2*j + 1;
            if (arr[idx] < arr[idx+1] && idx < (i-1))
                idx++;
            if (arr[j] < arr[idx] && idx < i)
                swap(&arr[j], &arr[idx]);
            
            j = idx;
        } while (idx < i);
    }
}

int main()
{
    int arr[] = {10, 20, 15, 17, 9, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
      
    printf("Given array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
          
    printf("\n\n"); 
  
    heapSort(arr, n);
  
    // print array after sorting
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
