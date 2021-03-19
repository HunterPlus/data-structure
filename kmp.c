#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* prekmp(char* s)
{
  int i, j, size;
  
  size = strlen(s);
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
  int i;
  int* p = prekmp(s);  
  int size = strlen(s);
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
      printf("Pattern occurs with shift %d\n", i-j);
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
