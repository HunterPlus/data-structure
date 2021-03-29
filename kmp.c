#include <stdio.h>
#include <stdlib.h>

int* prekmp(char* s)
{
  int i, j, size;
  
  for (size = 0; s[size] != '\0'; size++) ;
  
  int* p = (int*)malloc(size * sizeof(int));
  p[0] = 0;
  j = 0;
  for(i = 1; i < size; i++)
  {
    while(j > 0 && s[i] != s[j])
      j = p[j-1];
    if(s[i] == s[j])
      j++;
    p[i] = j;      
  }
  return p;
}
void kmp(char* txt, char* s)
{
  int i, size;
  
  int* p = prekmp(s); 
  
  for (size = 0; s[size] != '\0'; size++) ;
  
  for(i=0; i < size; i++)
  {
    printf("%d ", p[i]);    
  }
  printf("\n");
  int j = 0;
  for(i = 0; txt[i] != '\0'; i++)
  {
    while(j > 0 && s[j] != txt[i])
      j = p[j-1];
    if(s[j] == txt[i])
      j++;
    if(j == size)
    {
      printf("Pattern found at index %d\n", i-j+1);
      j = p[j-1];
    }
  }
}
  
  int main()
  {
    char* txt = "ABC ABCDAB ABCDABCDABDE";
    char* s = "ABCDABD";
    
    kmp(txt, s);
    return 0;
  }
