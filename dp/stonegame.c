#include <stdio.h>

int min (int a, int b, int c)
{
    int t = (a < b)? a : b;
    return (t < c)? t : c;
}

int findopt (int val[], int i, int n, int sum)
{
    if (n - i <= 3)
    {
        int s = 0;
        for (int j = i; j < n; j++)
            s += val[j];
        return s;
    }

    return sum - min(findopt(val, i+1, n, sum-val[i]),
                    findopt(val, i+2, n, sum-val[i]-val[i+1]),
                    findopt(val, i+3, n, sum - val[i]-val[i+1]-val[i+2]));
}
int optgame (int val[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += val[i];
    
    int s = findopt(val, 0, n, sum);
    if (2 * s > sum)
        printf("Win! %d---%d\n", s, sum);
    else
        printf("Lost! %d---%d\n", s, sum);
}

int main()
{
    int arr1[] = { 1, 2, 3, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    optgame(arr1, n);
 
    return 0;
}
