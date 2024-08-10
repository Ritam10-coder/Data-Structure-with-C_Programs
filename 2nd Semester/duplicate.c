#include<stdio.h>
int main()
{
	int ar[10],i,j,n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	printf("duplicate elements:\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ar[i]==ar[j+1])
			{
				printf("%d\n",ar[i]);
			}
		}
	}
	return 0;
}
