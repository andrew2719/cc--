#include<stdio.h>
int n;
int fun(int w[][100],int c[][100],int r[][100],int l,int h,int p[],int q[])
{
    //printf("v");
	int min=0;
	int i,j;
	w[l][h]=q[l];

	for(i=l;i<h;i++)
	w[l][h]=w[l][h]+p[i]+q[i+1];
	int k=0;
	min=10000;
	for(i=l+1;i<=h;i++)
	{
		int o= c[l][i-1]+c[i][h];
		if(o<min)
		{
		min=o;
		k=i;
		}
	}
    //printf("w : %d\n",w[l][h]);
	c[l][h]=min+w[l][h];
	r[l][h]=k;

}

void fun(int r[][100],int i,int j,int k)
{
	if(i==j)
	return;

	printf("Left child of %d is :: %d\n",k,r[i][k-1]);
	printf("Right child of %d is :: %d\n",k,r[k][j]);
	
	int y=r[i][j];
	int q=r[i][j]-1;
	int p=r[i][y-1];
	int t=r[i][j];
	int o=r[t][j];
	fun(r,i,q,p);
	fun(r,t,j,o);
}
int main()
{
	scanf("%d",&n);
	int p[n];
	int q[n+1];
	int i,j;
	for(i=0;i<n;i++)
	scanf("%d",&p[i]);
	for(i=0;i<n+1;i++)
	scanf("%d",&q[i]);

	int w[n+1][n+1];
	int c[n+1][n+1];
	int r[n+1][n+1];

	n=n+1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				w[i][j]=q[i];
				c[i][j]=0;
				r[i][j]=0;
			}	
		}
	}
	int k=1;
	int m=0;
	while(k!=n+1)
	{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		    //printf("%d %d\n",i+k,j);
			if((i+k)==j)
			{
			    //printf("%d %d\n",i,j);
				fun(w,c,r,i,j,p,q);
			}
		}
		
	}
	k=k+1;
	}
	printf("Optimal BST is :: w values are:\n");
	k=0;
	while(k!=n+1)
	{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((i+k)==j)
			{
			    printf("%d ",w[i][j]);
			}
		}
	}
	k=k+1;
	if(k!=n)
	printf("\n");
	}
	k=0;
	printf("c values are:\n");

	while(k!=n+1)
	{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((i+k)==j)
			{
			    printf("%d ",c[i][j]);
			}
		}
	}
	k=k+1;
	if(k!=n)
	printf("\n");
	}
	k=0;
	printf("r values are:\n");

	while(k!=n+1)
	{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((i+k)==j)
			{
			    printf("%d ",r[i][j]);
			}
		}
	}
	k=k+1;
	if(k!=n)
	printf("\n");
	}

	 int v=n-1;
	printf("Root is %d\n",r[0][v]);
	k=r[0][v];
	fun(r,0,v,k);
	

	
}