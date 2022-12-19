#include<stdio.h>
#include<stdlib.h>



int mod[1000000];
struct node
{
    int data;
    struct node *next;
};

//inserting
struct node* insert(struct node *head,int x)
{
    if(head==NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));
        head->data = x;
        head->next = NULL;
        return head;
    }
    else
    {
        struct node *new  = (struct node*)malloc(sizeof(struct node));
        new->data = x;
        new->next = NULL;
        struct node *temp = head;
        while (temp->next!=NULL)
        {
            temp  = temp->next;
        }
        temp->next  = new;
        return head;
    }
}

//deleting a specific node(head,node number)
struct node* del(struct node *head,int nd)
{
    struct node *temp ;
    temp = head;
    int c=1;
    
    while(c!=nd)
    {
        c++;
        if(c==nd)
        {
           struct node *temp2 = temp->next;
           temp->next = temp2->next ;
           free(temp2);
           break;
        }
        temp = temp->next;
    }
    if(c==1)
    {
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    return head;
   
}

//reverse the list
struct node* reverse(struct node *head)
{
    struct node *prev,*curr,*nxt;
    prev = NULL;
    curr = head;
    nxt = head;
    while (nxt!=NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    //head = prev;
    return prev;
    
}

//reverse_btw_ specific_nodes
struct node* reverse_btw_nodes(struct node *head,int start,int end)
{
    /*struct node *curr = head,*prev = NULL;
    int pos = 1;
    while(pos++<start)
    {
        prev = curr;
        curr = curr->next;

    }
    struct node *orgprev = prev,*orgcurr = curr;
    struct node *nxt;
    while(pos<=end && curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        pos++;
    }
    orgcurr->next = curr;
    if(orgprev)
    {
        orgprev->next = prev;
        return head;
    }
    else
    return head;*/

    if(start==end)
    return head;
    struct node *node_start = NULL,*original_prev = NULL;
    struct node *node_end = NULL,*original_end = NULL;

    int i=1;
    struct node *curr = head;
    while(curr && i<=end)
    {
        if(i<start)
        {
            original_prev = curr;

        }
        if(i==start)
        {
            node_start = curr;
        }
        if(i==end)
        {
            node_end = curr;
            original_end = curr->next;
        }
        curr = curr->next;
        i++;

    }
    node_end->next = NULL;
    node_end = reverse(node_start);

    if(original_prev)
    original_prev->next = node_end;
    else
    head = node_end;

    node_start->next = original_end;
    return head;

}

struct node* start_ends(struct node *head)
{
    struct node *temp = head;
    struct node *orghead = (struct node*)malloc(sizeof(struct node));
    orghead->next = head;
    struct node *orgcurr = (struct node*)malloc(sizeof(struct node));
    
    int start ,end,c=1;
    while(temp->next!=NULL)
    {
        if((temp->data)%2==0)
        {
            start = c;
            while ((temp->data)%2==0 || temp->next!=NULL)
            {
                temp = temp->next;
                c++;
            }
            end = c;
            //orgcurr->next = temp;
            //if(end-start!=1)
            orgcurr->next = reverse_btw_nodes(orghead->next,start,end);
            //temp = orgcurr->next;
        }
        else{
        temp = temp->next;
        c++;
        }
    }
    //orghead->next = reverse(temp);
    return orgcurr->next;
}

//printin list
void print(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }

}


void traverse(struct node *head,int n)
{
    for(int i=0;i<n || head->next!=NULL ;i++)
    {
        if(head->data%2==0)
        {
            mod[i] = 1;
        }
        head = head->next;
    }
}
int main()
{
    int n=9;
    //scanf("%d",&n);
    struct node *head = NULL;
    int a[] = {2,18,24,3,5,7,9,6,12};
    for(int i=0;i<n;i++)
    {
        //int x;
        //scanf("%d",&x);
        head = insert(head,a[i]);

    }
    
    traverse(head,n);

    int posi = 1;
    int j;
    for(int i=0;i<n;i++)
    {
        if(mod[i]==1)
        {
            for(j=i;mod[j]==1 || j<n ;j++)
            {
                posi++;
            }
            head = reverse_btw_nodes(head,i+1,posi);
            i+=j;
        }
    }
    print(head);
    //print(head);



}