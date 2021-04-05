#include <stdio.h>

void reverseArray (int arr[], int n)
{
    int i, j, t;
    
    for (i=0, j=n-1; i < j; i++, j--)
    {
        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    
    reverseArray(arr, n);
    printf("Reversed array is \n");
    printArray(arr, n);

    return 0;
}
