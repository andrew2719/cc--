#include<stdio.h>
#include<stdlib.h>
#define P(x) printf("%d",x)
#define P_(x) printf("%d ",x)
#define S(x) scanf("%d",&x)
#define n_l printf("\n")
#define SS(x,y) scanf("%d %d",&x,&y)
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b
int *stack,top;
int main()
{
    int t;
    S(t);
    while(t--)
    {
        top=-1;
        int n,k;
        SS(n,k);
        if(n==k)
        {
        printf("%d",0);
        printf("\n");
        }
        else
        {
            stack = (int*)calloc(n,sizeof(int)); // stack[5]  = [25],[],[],[],[]
            int x;
            S(x); //stack[top]
            top++; // top = 0
            stack[top] = x; //stack[0] = 25
            n--;
            while(n--)
            {
                S(x); //45,x = 45,x = 75,18
                while (k && x>stack[top] && top!=-1) // k = 3,45>stack[0] = 25 // k = 2,11>45 //2,75>11 //74>45
                {
                    top--; //top = -1 //top 1----top 0 //top =-1
                    k--; //2 //1 //k=0
                }
                top++; //0 //1 //top = 0//1
                stack[top] = x; // stack[0] = 45 //stack[1] = 11 //stack[0] = 75
            }
            while(k)
            {
                top--;
                k--;
            }
            for(int i=0;i<=top;i++)
            P_(stack[i]);
            n_l;
        }
    }
}
