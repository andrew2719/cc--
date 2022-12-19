#include<stdio.h>
#include<stdlib.h>
#define P(s) printf("%d",s)
#define S(s) scanf("%d",&s)


char *stack;
int top = -1;
struct node
{
    char *chr;
    struct node *next;
};


struct node* insert(struct node *head,char *x)
{
    if(head==NULL)
    {
        struct node *head = (struct node*)malloc(sizeof(struct node));
       
        head->chr = x;
        head->next = NULL;
        return head;
    }
    else
    {
        struct node *new = (struct node*)malloc(sizeof(struct node));
        struct node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        new->chr = x;
        new->next = NULL;
        temp->next = new;
    }
    return head;
}

void print(struct node *head)
{
    int c=1;
    while(head!=NULL)
    {
        printf("%c ",head->chr);
        head = head->next;
    }
    //sreturn c;
}

void stacking(struct node *head)
{
    while(head->next!=NULL)
    {
        stack[top]  = head->chr;
        head = head->next;
        top++;
    }
}

int is_pal(struct node *head)
{
    while(head->next!=NULL && top!=-1)
    {
        if(stack[top]!=head->chr)
        return 0;
        top--;
        head = head->next;
    }
    
    return 1;
}


int main()
{
    int n;
    S(n);
    struct node *head = NULL;
    char x[1];
    stack = (char*)malloc(n*sizeof(char));
    top++;
    for(int i=0;i<n;i++)
    {
        scanf("%c",&x);
        head = insert(head,x);
    }
    stacking(head);
    int flag = is_pal(head);
    P(flag);
    //print(head);
}