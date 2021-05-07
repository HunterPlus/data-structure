#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8
#define M 8

int dx[M] = {1,1,2,2,-1,-1,-2,-2};
int dy[M] = {2,-2,1,-1,2,-2,1,-1};

int safe (int a[], int x, int y)
{
    int e = a[x * N + y];
    if (x >= 0 && x < N && y >= 0 && y < N)
        return e == -1;
    return 0;
}
int getdegree (int a[], int x, int y)
{
    int deg = 0;
    for (int i = 0; i < M; i++)
        if (safe(a, x+dx[i], y+dy[i]))
            deg++;
    return deg;
}
int nextmove (int a[], int *x, int *y)
{
    int idx = -1;
    int deg = M+1;
    
    int nx, ny;
    int start = rand() % M;
    for (int count = 0; count < M; count++)
    {
        int i = (start + count) % M;
        nx = *x + dx[i];
        ny = *y + dy[i];
        
        int c;
        if (safe(a, nx, ny) && (c = getdegree(a, nx, ny)) < deg)
        {
            idx = i;
            deg = c;
        }
    }
    if (idx == -1)
        return 0;
        
    nx = *x + dx[idx];
    ny = *y + dy[idx];
    
    a[nx * N + ny] = a[(*x) * N + *y] + 1;
    
    *x = nx;
    *y = ny;
    
    return 1;
}
int neighbour (int x, int y, int xx, int yy)
{
    for (int i = 0; i < M; i++)
        if ((x+dx[i] == xx) && (y+dy[i] == yy))
            return 1;
    return 0;
}
void print2D(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d\t",a[i*n + j]);
        printf("\n");
    }
}
int findclosedtour (int a[])
{
    for (int i = 0; i < N*N; i++)
        a[i] = -1;
        
    int sx = rand() % N;
    int sy = rand() % N;
    
    int x = sx;
    int y = sy;
    a[x * N + y] = 1;
    for (int i = 0; i < N*N-1; i++)
        if (nextmove(a, &x, &y) == 0)
            return 0;
    if (neighbour(x, y, sx, sy) == 0)
        return 0;
        
    printf("start point: %d  %d\n", sx, sy);
    print2D(a, N);
    return 1;
}
void knighttour ()
{
    int a[N*N];
    
    srand(time(NULL));
    while (!findclosedtour(a))
    {
        ;
    }
}
int main()
{
    knighttour();

    return 0;
}
