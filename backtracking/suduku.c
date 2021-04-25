#include <stdio.h>
#define N 9

int printsudoku (int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", arr[i][j]);
        printf("\n");
    }
}
int safe (int grid[N][N], int row, int col, int num)
{
    for (int i = 0; i < N; i++)
        if (grid[i][col] == num)
            return 0;
    for (int j = 0; j < N; j++)
        if (grid[row][j] == num)
            return 0;
    int startrow = row - row % 3;
    int startcol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startrow + i][startcol + j] == num)
                return 0;
                
    return 1;
}
int findnext (int grid[N][N], int *row, int *col)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}
int sudoku (int grid[N][N])
{
    int row, col;
    if (!findnext(grid, &row, &col))
        return 1;
    for (int num = 1; num <= 9; num++)
    {
        if (safe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (sudoku(grid))
                return 1;
                
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
                       
    if (sudoku(grid) == 1)
        printsudoku(grid);
    else
        printf("No solution exists");

    return 0;
}
