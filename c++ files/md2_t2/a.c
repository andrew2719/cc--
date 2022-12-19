#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(int i,int j,int a[])
{

    int mid = (i+j)/2;
    struct node* root = newnode(a[mid]);
    if(i==j)
        return root;
    if(i<mid){
        printf("left =");
        for(int k=i;k<mid;k++)
        printf("%d ",a[k]);
        printf("\n");
        root->left = insert(i,mid-1,a);
    }
    if(mid<j)
    {
        printf("right =");
        for(int k=mid+1;k<=j;k++)
            printf("%d ",a[k]);
        printf("\n");
        root->right = insert(mid+1,j,a);
    }
    return root;

}
void inorder(struct node* root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    inorder(root->left);
    inorder(root->right);
}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};int n = sizeof(a)/sizeof(a[0]);
    struct node* root = malloc(sizeof(struct node));
    root = insert(0,n-1,a);
    inorder(root);
}