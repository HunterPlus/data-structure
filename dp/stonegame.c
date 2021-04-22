#include <stdio.h>

int min (int a, int b, int c)
{
    int t = (a < b)? a : b;
    return (t < c)? t : c;
}

int findopt (int val[], int i, int n, int sum)
{
    if (i == n-1)
        return val[i];
        
    int x = findopt(val, i+1, n, sum-val[i]);
    int y = (i+2 < n)? findopt(val, i+2, n, sum-val[i]-val[i+1]) : 0;
    int z = (i+3 < n)? findopt(val, i+3, n, sum - val[i]-val[i+1]-val[i+2]) : 0;
    
    return sum - min(x, y, z);
}
int optgame (int val[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += val[i];
    
    int s = findopt(val, 0, n, sum);
    if (2 * s > sum)
        printf("Win! %d<--->%d\n", s, sum);
    else if (2 * s < sum)
        printf("Lost! %d<--->%d\n", s, sum);
    else
        printf("Tie! %d<--->%d\n", s, sum);
}

int main()
{
    int arr1[] = { 1,2,3,-1,-2,-3,7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    optgame(arr1, n);
 
    return 0;
}
