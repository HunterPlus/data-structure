#include <stdio.h>
#include <stdlib.h>

#define HL    128

struct huffcode
{
    char ch;
    int freq;
    char *codes;
};
struct node
{
    char ch;
    int freq;
    struct node *l, *r;
};
struct heap
{
    int size;
    int cap;
    struct node **arr;
};

static struct node *root = NULL;
static struct huffcode hufftable[HL] = {0, 0, NULL};
/*******************************************************************/
void huffmancodes (char *msg);
char *msgencoding (char *msg);
char *msgdecoding (char *msgcodes);

char *createmsgcodesbuff (char *msg);
struct node *newnode (char ch, int freq);
struct heap *createheap (int capacity);
void swapnode (struct node **a, struct node **b);
void heapify (struct heap *hp, int i);
struct node *exactheap (struct heap *hp);
void insertheap (struct heap *hp, struct node *nd);
void buildheap (struct heap *hp);
struct heap *createandbuildheap (char data[], int freq[], int n);
struct node *huffmantree (char data[], int freq[], int n);

void formatmsg (char *msg, char **chs, int **freq, int *nodes);
void storecodes(struct node *root, char *codebuffer, int top, struct huffcode *hfc);

/********************************************************************/
void huffmancodes (char *msg)
{
    char *chs;
    int *freq, n;
    formatmsg(msg, &chs, &freq, &n);
    
    for (int i = 0; i < n; i++)
    {
        int idx = chs[i];
        hufftable[idx].ch = 1;
        hufftable[idx].freq = freq[i];
    }

    root = huffmantree(chs, freq, n);
    free(chs);
    free(freq);
    
    char codebuffer[HL] = { 0 };
    int top = 0;

    storecodes(root, codebuffer, top, hufftable);    
}

char *msgencoding (char *msg)
{
    char *msgcodes = createmsgcodesbuff(msg);
        
    int l = 0;
    for (int i = 0; msg[i] != '\0'; i++)
    {
        char *codes = hufftable[msg[i]].codes;
        for (int j =0; codes[j] != '\0'; j++)
            msgcodes[l++] = codes[j];
    }
    msgcodes[l] = '\0';
    return msgcodes;
}

char *msgdecoding (char *msgcodes)
{
    int l;
    while (msgcodes[l] != '\0')
        l++;
        
    char *msg = (char *)malloc(l * sizeof(char));
    struct node *cur = root;
    int j = 0;
    
    for (int i = 0; i < l; i++)
    {
        if (msgcodes[i] == '0')
            cur = cur->l;
        else
            cur = cur->r;
        
        if (!cur->l && !cur->r)
        {
            msg[j++] = cur->ch;
            cur = root;
        }
    }
    msg[j] = '\0';
    return msg;
}

char *createmsgcodesbuff (char *msg)
{
    int maxcodelen = 0;
    for (int i = 0; i < HL; i++)
    {
        if (hufftable[i].ch)
        {
            int l = 0;
            while (hufftable[i].codes[l] != '\0')
                l++;
            
            maxcodelen = (l > maxcodelen)? l : maxcodelen;
        }
    }
    int n;
    for (n = 0; msg[n] != '\0'; n++) ;
    
    int l = n * maxcodelen;
    char *msgcodes = (char *)malloc(l * sizeof(char));
    for (int i = 0; i < l; i++)
        msgcodes[i] = 0;
        
    return msgcodes;
}
struct node *newnode (char ch, int freq)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->ch = ch;
    t->freq = freq;
    t->l = t->r = NULL;
    return t;
}
struct heap *createheap (int capacity)
{
    struct heap *hp = (struct heap*)malloc(sizeof(struct heap));
    hp->size = 0;
    hp->cap = capacity;
    hp->arr = (struct node**)malloc(capacity * sizeof(struct node*));
    
    return hp;
}
void swapnode (struct node **a, struct node **b)
{
    struct node *t = *a;
    *a = *b;
    *b = t;
}
void heapify (struct heap *hp, int i)
{
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < hp->size && hp->arr[left]->freq < hp->arr[min]->freq)
        min = left;
    if (right < hp->size && hp->arr[right]->freq < hp->arr[min]->freq)
        min = right;
    if (min != i)
    {
        swapnode(&hp->arr[i], &hp->arr[min]);
        heapify(hp, min);
    }
}
struct node *exactheap (struct heap *hp)
{
    if (hp->size == 0)
        return NULL;
        
    struct node *t = hp->arr[0];
    hp->arr[0] = hp->arr[hp->size - 1];
    
    hp->size--;
    heapify(hp, 0);
    
    return t;
}
void insertheap (struct heap *hp, struct node *nd)
{
    hp->size++;
    int i = hp->size - 1;
    while (i > 0 && nd->freq < hp->arr[(i-1) / 2]->freq)
    {
        hp->arr[i] = hp->arr[(i-1) / 2];
        i = (i-1) / 2;
    }
    hp->arr[i] = nd;
}
void buildheap (struct heap *hp)
{
    int j = hp->size - 1;
    int i;
    
    for (i = (j-1) / 2; i >= 0; i--)
        heapify(hp, i);
}

struct heap *createandbuildheap (char data[], int freq[], int n)
{
    struct heap *hp = createheap(n);
    
    for (int i = 0; i < n; i++)
        hp->arr[i] = newnode(data[i], freq[i]);
   
    hp->size = n;
    buildheap(hp);
    return hp;
}
struct node *huffmantree (char data[], int freq[], int n)
{
    struct node *left, *right, *top;
    struct heap *hp = createandbuildheap(data, freq, n);
    
    while (hp->size > 1)
    {
        left = exactheap(hp);
        right = exactheap(hp);
        
        top = newnode('$', left->freq + right->freq);
        
        top->l = left;
        top->r = right;
        
        insertheap(hp, top);
    }
    return exactheap(hp);
}

void formatmsg (char *msg, char **chs, int **freq, int *nodes)
{
    int ht[128] = { 0 };
    int msglength, n;
    
    int i, j, c;
    for (i = 0; (c = msg[i]) != '\0'; i++)
        ht[c] += 1;
    msglength = i;
    
    for (n = 0, i = 0; i < 128; i++)
        if (ht[i] != 0)
            n += 1;
    *nodes = n;
            
    *chs = (char *)malloc((n+1) * sizeof(char));
    *freq = (int *)malloc(n * sizeof(int));
    for (j = 0, i = 0; i < 128; i++)
    {
        if (ht[i] != 0)
        {
            (*chs)[j] = i;
            (*freq)[j] = ht[i];
            j++;
        }
    }
    (*chs)[j] = '\0';
    
}
void storecodes(struct node *root, char *codebuffer, int top, struct huffcode *hfc)
{
    if (root->l)
    {
        codebuffer[top] = '0';
        storecodes(root->l, codebuffer, top+1, hfc);
    } 
    if (root->r)
    {
        codebuffer[top] = '1';
        storecodes(root->r, codebuffer, top+1, hfc);
    }
    if (!root->l && !root->r)
    {
        char c = root->ch;

        char *codes = (char *)malloc((top+1) * sizeof(char));
        for (int i = 0; i < top; i++)
            codes[i] = codebuffer[i];
        codes[top] = '\0';
        
        hfc[c].codes = codes;
    }
}

int main()
{
    char *msg = "good good study, day day up!";
     
    huffmancodes(msg);
    
    for (int i = 0; i < HL; i++)
    {
        if (hufftable[i].ch)
            printf("[%c : %d]\t%s\n", i, hufftable[i].freq,
                hufftable[i].codes);
    } 
    
    char *msgcodes = msgencoding(msg);
    printf("\n%s\n", msgcodes);
    
    char *msgfromcodes = msgdecoding(msgcodes);
    printf("\n%s\n", msgfromcodes);
    
    return 0;
}
