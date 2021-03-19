struct node
{
  struct node *newnode;
  struct node *left;
  struct node *right;
};
struct node *newnode(int data)
{
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->left = node->right = NULL;
  return node;
}
