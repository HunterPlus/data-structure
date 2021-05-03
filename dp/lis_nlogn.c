#include <stdio.h>

int getidx (int arr[], int l, int r, int key)
{
    int m;
    
    while (r - l > 1)
    {
        m = (l + r) / 2;
        if(arr[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int lis (int a[], int n)
{
    if (n == 0)
        return 0;
    
    int l = 1;    
    int order[n];
    for (int i = 0; i < n; i++)
        order[i] = 0;
    
    order[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < order[0])
            order[0] = a[i];
        else if (a[i] > order[l - 1])
            order[l++] = a[i];
        else
            order[getidx(order, -1, l-1, a[i])] = a[i];
    }
    for(int i = 0; i < n; i++)
        printf("%2d ", order[i]);
    printf("\nLIS is: %d", l);
    
    return l;
}

int main()
{
    int a[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int n = sizeof(a) / sizeof(a[0]);
    
    lis(a, n);

    return 0;
}
