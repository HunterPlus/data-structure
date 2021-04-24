#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

static int cx[N] = {1, 1, 2, 2, -1, -1, -2, -2};
static int cy[N] = {2, -2, 1, -1, 2, -2, 1, -1};

int limits(int x, int y)
{
    return ((x >= 0 && y >= 0) && (x < N && y < N));
}
int isempty(int a[], int x, int y)
{
    return limits(x, y) && (a[x * N + y] < 0);
}
int getdegree(int a[], int x, int y)
{
    int count = 0;
    for (int i = 0; i < N; i++)
        if (isempty(a, x + cx[i], y + cy[i]))
            count++;

    return count;
}
int nextmove(int a[], int *x, int *y)
{
    int min_deg_idx = -1;
    int min_deg = N + 1;
    int nx, ny, c;

    int start = rand() % N;
    for (int count = 0; count < N; count++)
    {
        int i = (start + count) % N;
        nx = *x + cx[i];
        ny = *y + cy[i];
        if (isempty(a, nx, ny) &&
            (c = getdegree(a, nx, ny)) < min_deg)
        {
            min_deg_idx = i;
            min_deg = c;
        }
    }
    if (min_deg_idx == -1)
        return 0;

    nx = *x + cx[min_deg_idx];
    ny = *y + cy[min_deg_idx];

    a[nx * N + ny] = a[(*x) * N + (*y)] + 1;

    *x = nx;
    *y = ny;

    return 1;
}

void print(int a[])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            printf("%d\t", a[i * N + j]);
        printf("\n");
    }
}
int neighbour(int x, int y, int xx, int yy)
{
    for (int i = 0; i < N; i++)
        if ((x + cx[i] == xx) && (y + cy[i] == yy))
            return 1;
    return 0;
}
int findclosedtour()
{
    int a[N * N];
    for (int i = 0; i < N * N; i++)
        a[i] = -1;

    int sx = rand() % N;
    int sy = rand() % N;

    int x = sx, y = sy;
    a[x*N + y] = 1;

    for (int i = 0; i < N*N - 1; i++)
        if (nextmove(a, &x, &y) == 0)
            return 0;
        
    if (!neighbour(x, y, sx, sy))
        return 0;

    print(a);
    return 1;
}

int main()
{
    srand(time(NULL));

    while (!findclosedtour())
    {
        ;
    }

    return 0;
}
