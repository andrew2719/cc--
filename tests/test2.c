#include<stdio.h>
int main()
{
	long int n;
	scanf("%ld",&n);
	long int a[n];
	long int b[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
		scanf("%ld",&b[i]);
	}
	long int a1[n],a2[n];
	for(i=0;i<n;i++)
	{
	a1[i]=a[i];
	a2[i]=a[i];
	}
	long int max=b[0];
	for(i=0;i<n;i++)
	{
		if(b[i]>max)
		max=b[i];
	}
	long int m[max];
	for(i=0;i<max;i++)
	m[i]=-1;
	long int c=0;
	int p=0;
	while(c<max && p<n)
	{
		long int vin=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>a[vin])
			vin=i;
		}
		a[vin]=-1;
		long int v=b[vin];
		long int j;
		for(j=v-1;j>=0;j--)
		{
			if(m[j]==-1)
			{
				m[j]=vin+1;
				c=c+1;
				break;
			}
		}
		p=p+1;
	}
	printf("INDEX\tPROFIT\tDEADLINE\tSLOT ALLOTTED\n");
	long int j;
	for(i=0;i<n;i++)
	{
		int maxi=a1[0],l=0;
		for(j=0;j<n;j++)
		{
			if(a1[j]>maxi)
			{
			maxi=a1[j];
			l=j;
			}
		}
		a1[l]=-1;
	
		int x=0,z=0;
		for(int k=0;k<max;k++)
		{
			if(m[k]-1==l)
			{
				x=1;
				z=k;
			}
		}
			if(x==1)
			printf("J%ld\t%ld\t%ld\t[%ld-%ld]\n",l+1,a2[l],b[l],z,z+1);
			else
			printf("J%ld\t%ld\t%ld\tREJECTED\n",l+1,a2[l],b[l]);
	}
}
