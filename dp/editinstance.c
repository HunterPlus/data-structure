#include <stdio.h>

int min (int x, int y, int z)
{
    int t = (x < y)? x : y;
    return (t < z)? t : z;
}
int editdist (char *s1, char *s2, int n1, int n2)
{
    int dp[n1+1][n2+1];
    int i, j;
    for (i = 0; i < n1+1; i++)
    {
        for (j = 0; j < n2+1; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }
    for (i = 0; i < n1+1; i++)
    {
        for (j = 0; j < n2+1; j++)
            printf("%d\t", dp[i][j]);
        printf("\n");
    }
    return dp[n1][n2];
}

int main()
{
    int n1, n2;
    char *s1 = "sunday";
    char *s2 = "saturday";
    
    for (n1 = 0; s1[n1] != '\0'; n1++) ;
    for (n2 = 0; s2[n2] != '\0'; n2++) ; 
    
    editdist(s1, s2, n1, n2);

    return 0;
}
