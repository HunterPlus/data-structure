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
int nextmove (int a[], int *x, int *y, int step)
{
    if (step == N*N)
        return 1;
        
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

    nextmove(a, x, y, step+1);
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
void findclosedtour ()
{
    int a[N*N];
    srand(time(NULL));
    int sx, sy, x, y;
    sx = 2;
    sy = 3;
    
    printf("start point: %d  %d\n", sx, sy);
    for (; ;)
    {
        for (int i = 0; i < N*N; i++)
            a[i] = -1;

        x = sx;
        y = sy;
        a[x * N + y] = 1;    
        
        if (nextmove(a, &x, &y, 1) == 0)
            continue;
        print2D(a, N);
        printf("\n");
        if (neighbour(x, y, sx, sy))
        {
            printf("Msg:...........Closed Tour!\n");
            print2D(a, N);
            break;
        }
    }
}

int main()
{
    findclosedtour();

    return 0;
}
