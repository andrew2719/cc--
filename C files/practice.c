#include<stdio.h>
#include<stdlib.h>
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)


struct node
{
    int data;
    struct node *next;
};

struct node* insert(struct node *head,int x)
{
    if(head==NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));
        head->data = x;
        head->next = NULL;
        return head;
    }
    else{
        struct node *new = (struct node*)malloc(sizeof(struct node));
        new->data = x;
        new->next = NULL;
        struct node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        return head;
    }
}



static void reverseBetween(struct node* head, int left, int right){
    if (head->next == NULL || right == left)
        return;
    
    struct node* current = head;
    struct node* prev = NULL;
    struct node* next = NULL;
    
    //get the pointer to the starting position
    for (int i = 1; i < left; ++i){
        prev = current;
        current = current->next;
    }
    next = current->next;
    
    //check if head needs to be changed
    int yes = 0;
    if (current == head)
        yes = 1;
    
    //keep track of the node prev to the srarting position
    struct node* startPrev = prev;
    
    //keep track of the first node to be changed
    struct node* firstChanged = current;
    
    //move to the ending position while reversing the nodes
    for (int i = left; i <= right && current != NULL; ++i){
        current->next = prev;
        prev = current;
        current = next;
        if (current != NULL)
            next = current->next;
    }
    
    //fix the links of the starting and ending position
    if (yes == 1)
        head = prev;
    else if (startPrev != NULL)
        startPrev->next = prev;
    firstChanged->next = current;
    
    //return head;
}







void transervse_positions(struct node *head)
{
    int start_position,end_position,c=0;
    while(head!=NULL)
    {
        c++;
        if((head->data)%2==0)
        {
            start_position = c;
            while((head->data)%2==0)
            {
                head = head->next;
                if((head->data)%2==0)
                c++;
            }
            end_position = c;
            reverseBetween(head,start_position,end_position);
        }
        head = head->next;

    }
}

void print(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}




int main()
{
    struct node *head=NULL;
    int n;
    S(n);
    int c=0,fg = 0,f=0;
    int temp;
    for(int i=0;i<n;i++)
    {
        int x;
        S(x);
        head = insert(head,x);
    }
    transervse_positions(head);
    print(head);
}