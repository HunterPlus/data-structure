#include <stdio.h>

#define N 4

void printnq (int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}
int safe (int board[N][N], int r, int c)
{
    int i, j;
    
    for (j = 0; j < c; j++)
        if (board[r][j] == 1)
            return 0;
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;
    for (i = r, j = c; i >=0 && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return 0;
    
    return 1;
}
int nqueen (int board[N][N], int c)
{
    if (c >= N)
        return 1;
        
    for (int i = 0; i < N; i++)
    {
        if (safe(board, i, c) == 1)
        {
            board[i][c] = 1;
            if (nqueen(board, c+1) == 1)
                return 1;
                
            board[i][c] = 0;
        }
    }
    
    return 0;
}


int main()
{
   int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
                        
    if (nqueen(board, 0) == 0)
        printf("Solution does not exist!\n");
    else
    {
        printf("Solution is:\n");
        printnq(board);
    }
    

    return 0;
}
