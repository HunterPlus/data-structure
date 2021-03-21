#include <stdio.h>

int findElement (int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int insertElement (int arr[], int n, int key, int capacity)
{
    if (n >= capacity)
        return n;
    arr[n] = key;
    
    return (n+1);
}

void reverse (int arr[], int n)
{
    int i, j, t;
    
    for (i = 0,j = n-1; i < j; i++,j--)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

int deleteElement (int arr[], int n, int key)
{
    int pos = findElement(arr, n, key);
    if (pos == -1){
        printf("element not found.");
        return n;
    }
    
    int i;
    for (i = pos; i < n; i++)
        arr[i] = arr[i+1];
    
    return (n-1);
}

int insertSorted (int arr[], int n, int key, int capacity)
{
    if (n >= capacity)
        return n;
    
    int i;
    for (i = n-1; arr[i] > key; i--)
        arr[i+1] = arr[i];
    arr[i+1] = key;
    
    return (n+1);
}

int binarySearch (int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = (l+r) / 2;
        
        if (arr[m] == x)
            return m;
            
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int RbinarySearch (int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
        
    int mid = (low + high) / 2;
    
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid+1), high, key);
    return binarySearch(arr, low, (mid-1), key);
}

int deleteSorted(int arr[], int n, int key)
{
    int pos = binarySearch(arr, 0, n-1, key);
    
    if (pos == -1) {
        printf ("Element not found.");
        return n;
    }
    for (int i = pos; i < n-1; i++)
        arr[i] = arr[i+1];
        
    return (n-1);
}

int main()
{
    int i; 
    int arr[] = { 10, 20, 30, 40, 50 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
    int key = 30; 
  
    printf("Array before deletion\n"); 
    for (i = 0; i < n; i++) 
        printf("%d  ", arr[i]); 
  
    n = deleteSorted(arr, n, key); 
  
    printf("\n\nArray after deletion\n"); 
    for (i = 0; i < n; i++) 
        printf("%d  ", arr[i]);
  
    return 0;
}
