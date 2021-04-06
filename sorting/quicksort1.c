#include <stdio.h>

void swap (int *a, int *b) {int *t = *a; *a = *b; *b = *t; }

void quickSort (int arr[], int n)
{
    int i = 0;
    int j = n-1;
    int *qi = arr;
    int *qj = arr + j;
    int *qp = qj;
    
    while ( n > 1)
    {
        while (i < j)
        {
            while (i < j && *qi <= *qp)
               i++, qi++;
           while (i < j && *qj >= *qp)
               j--, qj--;
        
           if (i < j)
           {
               swap(qi, qj);
               i++, qi++;
           }
        }  
        if (qi != qp)
            swap(qi, qp);
    
        j = n - i - 1, qi++;
        
        if (j < i)
        {
            if (j > 1)
                quickSort(qi, j);
            n = i;
        }
        else
        {
            if (i > 1)
                quickSort(arr, i);
            arr = qi;
            n = j;
        }
    }
}

int main()
{
    printf("Hello World");

    return 0;
}
