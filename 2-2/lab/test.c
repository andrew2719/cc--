#include<stdio.h>
#define f(i,n) for(int i=0;i<n;i++)
#define s(n) scanf("%d",&n)
#define p(n) printf("%d ",n)
int n;
void fun(int a[][n],int b[][n],int i,int j,int k)
{
    int p=a[i][j];
    int q=a[i][k]+a[k][j];
    int c=0;
    c = (p<q)?p:q;
    
    b[i][j]=c;
    
}
int main()
{
    s(n);
    int a[n][n];
    
    f(i,n)f(j,n)s(a[i][j]);
    
    int k=0;
    f(i,n)
    {
        f(j,n)
        if(i!=j && a[i][j]==0)
        a[i][j]=999;
    }
    
    while(k<n)
    {
        int b[n][n];
        f(i,n)
        {
            f(j,n)  
            {
                if(i==k || j==k)
                b[i][j]=a[i][j];
                else
                b[i][j]=0; 
            }
        }
        
        f(i,n)
        {
            f(j,n)   
                if(i!=k && j!=k && i!=j)
                fun(a,b,i,j,k);
        }
        f(i,n)f(j,n)a[i][j]=b[i][j];
             
        k=k+1;
    }
     f(i,n)
        {
            f(j,n)   
            p(a[i][j]);
            printf("\n");
        }
}