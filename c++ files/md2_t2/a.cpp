#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(int i,int j,int a[])
{

    int mid = (i+j)/2;
    //cout<<"root = "<<a[mid]<<endl;
    Node* root = new Node(a[mid]);
    cout<<"root = "<<a[mid]<<endl;
    if(i==j) // it is a leaf node
        return root;
    if(i<mid){
        cout<<"left =";
        for(int k=i;k<mid;k++)
            cout<<a[k]<<" ";
        cout<<endl;
        root->left = insert(i,mid-1,a);
    }
    if(mid<j)
    {
        cout<<"right =";
        for(int k=mid+1;k<=j;k++)
            cout<<a[k]<<" ";
        cout<<endl;
        root->right = insert(mid+1,j,a);
    }
    return root;

}
void inorder(Node* root)
{
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main()
{
    int a[] = {45,56,66,67,89,100,512};int n = sizeof(a)/sizeof(a[0]);
    /*vector<int> v;
    for(int i=0;i<n;i++)
        v.push_back(a[i]);
    sort(v.begin(),v.end());*/
    Node *root = nullptr;
    root = insert(0,n-1,a);
    inorder(root);
}