#include <stdio.h>

void quicksort (int arr[], int l, int h);

int twocandidates (int a[], int n, int sum)
{
    int l, r;
    
    quicksort(a, 0, n-1);
    
    l = 0;
    r = n-1;
    while (l < r)
    {
        if (a[l] + a[r] == sum)
            return 1;
        else if (a[l] + a[r] > sum)
            r--;
        else
            l++;
    }
    return 0;
}

void swap (int *a, int *b) {int t = *a; *a = *b; *b = t; }

int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = l - 1;
    
    for (int j = l; j < h; j++)
        if (arr[j] <= x)
            swap(&arr[++i], &arr[j]);
    swap(&arr[++i], &arr[h]);
    
    return i;
}
void quicksort (int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        quicksort(arr, l, p-1);
        quicksort(arr, p+1, h);
    }
}

int main()
{
    int arr[] = { 1, 4, 45, 6, 10, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 5;
 
    if (twocandidates(arr, n, sum))
        printf("Array has two elements with given sum");
    else
        printf("Array doesn't have two elements with given sum");

    return 0;
}
