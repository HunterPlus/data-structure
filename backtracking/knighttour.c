#include <stdio.h>
#define N 8
#define M 8

struct Coord
{
    int x;
    int y;
};
struct Coord move[M] = {{2,1}, {1, 2}, {-1, 2}, {-2, 1}, 
                        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
                        
struct Coord KTmove (struct Coord a, struct Coord offset)
{
    struct Coord b;
    
    b.x = a.x + offset.x;
    b.y = a.y + offset.y;
    
    return b;
}
int safe (struct Coord coord, int chess[N][N])
{
    int x = coord.x;
    int y = coord.y;
    
    return (x>=0 && x<N && y>=0 && y<N && chess[x][y] == -1);
}
int knight (struct Coord start, int counter, int chess[N][N])
{
    struct Coord next;
    
    if (counter == N * N)
        return 1;
    
    for (int i = 0; i < M; i++)
    {
        next = KTmove(start, move[i]);
        if (safe(next, chess) == 1)
        {
            chess[next.x][next.y] = counter;
            if (knight(next, counter+1, chess) == 1)
                return 1;
            
            chess[next.x][next.y] = -1;
        }
    }
    return 0;
}

void printKT (int chess[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", chess[i][j]);
        printf("\n");
    }
}

void solveKT ()
{
    int chess[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            chess[i][j] = -1;
            
    int counter = 0;
    struct Coord start = { 0, 0 };
    chess[start.x][start.y] = counter;
    
    if (knight(start, counter+1, chess) == 0)
    {
        printf("Solution does not exist");
        return ;
    }
    printKT(chess);
}


int main()
{
    solveKT();

    return 0;
}
