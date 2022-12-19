
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *root = NULL;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);
    // left left case
    if (balance > 1 && data < node->left->data ){
      printf("left left rotation for %d\n", node->data);
        return rightRotate(node);
    }

// right right case
    if (balance < -1 && data > node->right->data){
      printf("right right rotation for %d\n", node->data);
        return leftRotate(node);
    }
// left right case
    if (balance > 1 && data > node->left->data)
    {
      printf("left right rotation for %d\n", node->data);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
// right left case
    if (balance < -1 && data < node->right->data)
    {
      printf("right left rotation for %d\n", node->data);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    int n;
  scanf("%d", &n);

  struct node* root = NULL;
  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    root = insert(root, val);
  }

    printf("Preorder traversal of the constructed AVL tree is : ");
    preOrder(root);
    
    return 0;
}
