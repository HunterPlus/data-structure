#include <stdio.h>

int getMax (int arr[], int n)
{
    int max = arr[0];
    
    for (int i = 1; i < n; i++)
        if (max < arr[i])
            max = arr[i];
            
    return max;
}
void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

void countSort (int arr[], int n, int exp)
{
    int count[10] = {0};
    int output[n];
    
    int h(int x) {return (arr[x]/exp) % 10;}
    
    int i;
    for (i = 0; i < n; i++)
        count[h(i)]++;
        
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
        
    for (i = n-1; i >= 0; i--)
    {
        output[count[h(i)] - 1] = arr[i];
        count[h(i)]--;
    }
    
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    
    printArray(arr, n);
}

void radixSort (int arr[], int n)
{
    int max = getMax(arr, n);
    int exp;
    
    for (exp = 1; max/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a) / sizeof(a[0]);
    printArray(a, n);
    
    radixSort(a, n);

    return 0;
}
