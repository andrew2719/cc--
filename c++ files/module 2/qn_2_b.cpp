#include<bits/stdc++.h>
using namespace std;
struct Node //struct declaraton
{
    int data;
    Node *left,*right;
};

Node* newnode(int data)// creating the node
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void paths(Node* node,int path[],int len);
void print(int path[],int len);

Node* insert(Node *node,int val) //  inserting the node
{
    if(node==NULL)
    return newnode(val);
    if(val<node->data)
        node->left = insert(node->left,val);
    else
        node->right = insert(node->right,val);
    return node;
}
void print_paths_and_sum(Node* node)
{
    int path[10000];
    paths(node,path,0);
}

void print(int path[],int len)
{
    int sum = 0;
    for(int i=0;i<len;i++)
    {
        cout<<path[i]<<" ";
        sum+=path[i];

    }
    cout<<" : "<<sum;
    cout<<endl;
}
void paths(Node* node,int path[],int len)
{
    if(node==NULL)
    return;
    path[len]=node->data;
    len++;
    if(node->left==NULL && node->right==NULL)
    print(path,len);
    else{
        paths(node->left,path,len);
        paths(node->right,path,len);
    }
}


int main()
{
    /*int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }*/
    int a[] = {4,2,1,3,6,5,7};int n = sizeof(a)/sizeof(a[0]);
    Node *root = nullptr;
    root = insert(root,a[0]);
    for(int i=1;i<n;i++)
    insert(root,a[i]);
    print_paths_and_sum(root);
    
    
}