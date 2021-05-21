#include <stdio.h>
#include <stdlib.h>

#define ALPHAS  26

struct TrieNode
{
    int eow;        //is End of Words
    struct TrieNode* children[ALPHAS];
};

struct TrieNode* getNode (void)
{
    struct TrieNode *t = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    
    t->eow = 0;
    for (int i = 0; i < ALPHAS; i++)
        t->children[i] = NULL;
    
    return t;
}
void insert (struct TrieNode **root, char* key)
{
    if (*root == NULL)
        *root = getNode();
        
    int l = 0;
    while (key[l])
        l++;
    
    struct TrieNode *t = *root;
    for (int i = 0; i < l; i++)
    {
        int idx = key[i] - 'a';
        if (!t->children[idx])
            t->children[idx] = getNode();
            
        t = t->children[idx];
    }
    
    t->eow = 1;
}
int search (struct TrieNode *root, char* key)
{
    int l = 0;
    while (key[l])
        l++;
        
    struct TrieNode *t = root;
    for (int i = 0; i < l; i++)
    {
        int idx = key[i] - 'a';
        if (!t->children[idx])
            return 0;
            
        t = t->children[idx];
    }
    
    return (t && t->eow);
}
int empty (struct TrieNode *root)
{
    for (int i = 0; i < ALPHAS; i++)
        if (root->children[i])
            return 0;
            
    return 1;
}
struct TrieNode* deleteutil (struct TrieNode *trie, char* key)
{
    if (trie == NULL)
        return NULL;
        
    if (*key == '\0')
    {
        if (trie->eow == 1)
            trie->eow = 0;
            
        if (empty(trie))
        {
            free(trie);
            trie = NULL;
        }
        return trie;
    }
    
    int idx = *key - 'a';
    trie->children[idx] = deleteutil(trie->children[idx], key+1);
    
    if (empty(trie) && trie->eow == 0)
    {
        free(trie);
        trie = NULL;
    }
    return trie;
}
void delete (struct TrieNode **root, char* key)
{
    if (*root == NULL)
        return;

    *root = deleteutil(*root, key);
}
void display (struct TrieNode *trie, char buffer[], int level)
{
    if (trie->eow == 1)
    {
        buffer[level] = '\0';
        printf("%s\n", buffer);
    }
    
    for (int i = 0; i < ALPHAS; i++)
    {
        if (trie->children[i])
        {
            buffer[level] = i + 'a';
            display(trie->children[i], buffer, level+1);
        }
    }
}

int main()
{
    char* keys[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    int n = sizeof(keys) / sizeof(keys[0]);
    
    struct TrieNode *root = NULL;
    for (int i = 0; i < n; i++)
        insert(&root, keys[i]);
        
    search(root, "the")? printf("Yes.\n") : printf("No.\n");
    search(root, "these")? printf("Yes.\n") : printf("No.\n");
    
    char buffer[20];
    display(root, buffer, 0);
    
    delete(&root, "heroplane");
    search(root, "hero")? printf("Yes.\n") : printf("No.\n");
    
    display(root, buffer, 0);
    return 0;
}
