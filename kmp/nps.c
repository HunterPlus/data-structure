#include <stdio.h>

void nps (char* pat, char* txt)
{
    int m, n;
    
    for (m = 0; pat[m] != '\0'; m++) ;
    
    for (n = 0; txt[n] != '\0'; n++) ;
    
    for (int i = 0; i < n-m; i++)
    {
        int j;
        
        for (j = 0; j < m; j++)
            if (txt[i+j] != pat[j])
                break;
        if (j == m)
            printf("Pattern found at index %d \n", i);
    }
}

int main()
{
    char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA";
    
    nps(pat, txt);

    return 0;
}
