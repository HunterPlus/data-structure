#include <stdio.h>

int count (int S[], int m, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (m <= 0 && n > 0)
        return 0;
        
    return count(S, m-1, n) + count(S, m, n - S[m-1]);
}

int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d \n", count(arr, m, 5));

    return 0;
}
/*
--> count()
                             C({1,2,3}, 5)                     
                           /             \    
                         /                 \                  
             C({1,2,3}, 2)                 C({1,2}, 5)
            /       \                      /      \         
           /         \                    /         \   
C({1,2,3}, -1)  C({1,2}, 2)        C({1,2}, 3)    C({1}, 5)
               /    \             /     \           /     \
             /       \           /       \         /        \
    C({1,2},0)  C({1},2)   C({1,2},1) C({1},3)    C({1}, 4)  C({}, 5)
                   / \     / \        /\         /     \         
                  /   \   /   \     /   \       /       \  
                .      .  .     .   .     .   C({1}, 3) C({}, 4)
                                               / \ 
                                              /   \   
                                             .      .
*/
