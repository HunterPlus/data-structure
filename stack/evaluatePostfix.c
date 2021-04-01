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
        if (exp[i] == ' ')
            i++;
            
        if (isdigit(exp[i]))
            stack[++top] = exp[i] - '0';        
        
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
    char exp[] = "231*+9-";
    printf ("postfix evaluation: %d", evaluatePostfix(exp));

    return 0;
}
