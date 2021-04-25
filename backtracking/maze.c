#include <stdio.h>
#define N 4
#define M 4
int cx[M] = {1, -1, 0, 0};
int cy[M] = {0, 0, 1, -1};

int safe (int maze[N][N], int x, int y)
{
    if (x>=0 && x<N && y>=0 && y < N && maze[x][y] == 1)
        return 1;
        
    return 0;
}
void printsolution (int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", sol[i][j]);
        printf("\n");
    }
}
int mazeutil (int maze[N][N], int sol[N][N], int x, int y)
{
    if (x == N-1 && y == N-1 && maze[x][y] == 1)
        return 1;

    for (int i = 0; i < M; i++)
    {
        int nx = x + cx[i];
        int ny = y + cy[i];
        if (safe(maze, nx, ny) && sol[nx][ny] == 0)
        {
            sol[nx][ny] = 1;
            if (mazeutil(maze, sol, nx, ny))
                return 1;
                
            sol[nx][ny] = 0;
        }
    }
    return 0;
}
int solvemaze (int maze[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 } };
                    
    int x = 0;
    int y = 0;
    sol[x][y] = 1;
    if (!mazeutil(maze, sol, x, y))
    {
        printf("solution is not exist!");
        return 0;
    }
    printsolution(sol);
    return 1;
}

int main()
{
    int maze[N][N] = { { 1, 0, 0, 0 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 1 } };
 
    solvemaze(maze);

    return 0;
}
