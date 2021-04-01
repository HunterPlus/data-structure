#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evaluatePostfix (char *exp)
{
    int *stack, top;
  
    for (top = 0; exp[top]; top++) ;
  
    stack = (int*)malloc(top * sizeof(int));
    top = -1;
    
    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] == ' ') continue;

        else if (isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
                num = 10 * num + (exp[i++] - '0');
            
            i--;
            stack[++top] = num;
        }
        else
        {
            int val1 = stack[top--];
            int val2 = stack[top--];
            
            switch (exp[i])
            {
                case '+': stack[++top] = val2 + val1; break;
                case '-': stack[++top] = val2 - val1; break;
                case '*': stack[++top] = val2 * val1; break;
                case '/': stack[++top] = val2 / val1; break;                
            }
        }
        
    }

    return stack[top--];
}

int main()
{
    char exp[] = "100 200 + 2 / 5 * 7 +";
    printf ("postfix evaluation: %d", evaluatePostfix(exp));

    return 0;
}
