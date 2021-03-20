#include <stdio.h>

int max(int a, int b) { return (a > b)? a : b; }

int knapsack(int wt[], int val[], int w, int n)
{
    if (w == 0 || n == 0)
        return 0;
        
    if (wt[n-1] > w)
        return knapsack(wt, val, w, n-1);
        
    else return max(
        val[n-1] + knapsack(wt, val, w-wt[n-1], n-1),
        knapsack(wt, val, w, n-1));
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int w = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapsack(wt, val, w, n));

    return 0;
}
