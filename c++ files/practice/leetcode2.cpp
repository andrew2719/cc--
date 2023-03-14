#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


//rotate the list K times
Node* rotate(Node* head, int k){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head;
    temp = head;
    while(k--){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}


void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


//insertion function
Node* insert(Node* head, int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head = temp;
        return head;
    }
    Node* temp = head;
    temp->next = insert(temp->next, data);
    return head;
}