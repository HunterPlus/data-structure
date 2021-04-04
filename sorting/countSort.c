#include <stdio.h>
#define RANGE 255

void countSort (char *s)
{
    int count[RANGE+1] = {0};
    
    int i;
    for (i = 0; s[i]; i++) ;
    char output[i];
    
    for (i =0; s[i]; i++)
        count[s[i]]++;
    
    for (i = 1; i <= RANGE; i++)
        count[i] += count[i-1];
    
    for (i = 0; s[i]; i++)
    {
        output[count[s[i]] - 1] = s[i];
        count[s[i]]--;
    }
    
    for (i = 0; s[i]; i++)
        s[i] = output[i];
}

int main()
{
    char arr[] = "goodgoodstudydaydayup";
  
    countSort(arr);
  
    printf("Sorted character array is %s\n", arr);

    return 0;
}
