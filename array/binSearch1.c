#include <stdio.h>

int binSearch (int arr[], int n, int key)
{
    int *p = arr;
    
    while (n > 0)
    {
        int mid = n >> 1;
        int *q = p + mid;
        
        if (key < *q)
            n = mid;
        else if (key == *q)
            return q - arr;
        else
        {
            p = q + 1;
            n -= mid + 1;
        }
    }
    
    return -1;
}

int main()
{
    int arr[] = {2,3,9,16,18,21,28,32,35};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int idx = binSearch(arr, n, 16);
    printf("index: %d\n", idx);

    return 0;
}
