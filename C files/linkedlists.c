#include<stdio.h>
#include<stdlib.h>
#define P(s) printf("%d",s)
#define S(s) scanf("%d",&s)

struct node
{
    int id,age;
    char *name,*branch;
    struct node *next;
};

struct node* insert(struct node *head,int id,char name[],int age,char branch[])
{
    if(head==NULL)
    {
        struct node *head = (struct node*)malloc(sizeof(struct node));
       
        head->id = id;
        head->name = name;
        head->age = age;
        head->branch = branch;
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
        new->id = id;
        new->name = name;
        new->age = age;
        new->branch = branch;
        new->next = NULL;
        temp->next = new;
    }
   
    return head;
}

int print(struct node *head)
{
    int c=1;
    while(head!=NULL)
    {
        printf("id : %d\n",head->id);
        printf("age : %d\n",head->age);
        printf("name : %s\n",head->name);
        printf("branch : %s\n",head->branch);
        head = head->next;
    }
    return c;
}

int main()
{
    int n;
    S(n);
    struct node *head = NULL;
    int id,age;
    char name[20],branch[5];
    /*S(id);
    S(age);
    scanf(" %s",name);
    scanf(" %s",branch);*/
    for(int i=0;i<n;i++)
    {
        scanf("%d",&id);
        scanf("%d",&age);
        scanf("%s",name);
        scanf("%s",branch);
        head = insert(head,id,name,age,branch);
    }
    int len = print(head);
    if(len!=1)
    P(len-1);
    else
    P(len+1);
}
