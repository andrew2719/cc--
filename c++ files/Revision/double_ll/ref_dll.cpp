#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev,*next;
    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

Node* double_ll_insert(Node* head, int val)
{
    Node* temp = head;
    if(head==NULL)
    {
        return new Node(val);
    }
    else{
        temp->next = double_ll_insert(temp->next,val);
        temp->next->prev = head;
    }

    return head;
    
}
void print(Node* head)
{
    Node* prev = head;
    cout<<"\nfrom front\n";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        prev = head;
        head = head->next;
    }
    cout<<"\nfrom back\n";
    while (prev!=NULL)
    {
        cout<<prev->data<<" ";
        prev = prev->prev;
    }
    

}
int main()
{
    int n;
    int a[] = {1,2,3,5,6};
    n = sizeof(a)/sizeof(a[0]);
    Node* head  = double_ll_insert(NULL,a[0]);
    for(int i=1;i<n;i++)
    double_ll_insert(head,a[i]);
    print(head);
    cout<<'\n';

    
}