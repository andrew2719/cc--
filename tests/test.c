#include<stdio.h>
int orgnanize_pos_neg(int *a1, int *a2, int size)
{
	// a1 contains only positive and a2 contains only negative numbers after completion of this function
	// they are in sorted order
	int temp[2*size];
	for(int i=0;i<size;i++)
	{
		temp[i]=a1[i];
		temp[i+size]=a2[i];
	}

	// sorting
	for(int i=0;i<2*size;i++)
	{
		for(int j=i+1;j<2*size;j++)
		{
			if(temp[i]>temp[j])
			{
				int t=temp[i];
				temp[i]=temp[j];
				temp[j]=t;
			}
		}
	}
	// separate  to a1 and a2
	int i=0;
	for(;i<size;i++)
	{
		a2[i]=temp[i];
	}
	for(int j=0;j<size;j++)
	{
		a1[j]=temp[i];
		i++;
	}
	return 0;
    
}
void print_array(int a[],int size)
{
    int i;
    for(i=0;i<size; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

int main()
{
    int i,j,n,len,res;
    int arr1[20];
    int arr2[20];
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &len);
        
        for(j=0;j<len;j++)
            scanf("%d", &arr1[j]);
    
        for(j=0;j<len;j++)
            scanf("%d", &arr2[j]);
            
        orgnanize_pos_neg(arr1, arr2, len);
        
        print_array(arr1,len);
        print_array(arr2,len);
    }
    return 0;
}