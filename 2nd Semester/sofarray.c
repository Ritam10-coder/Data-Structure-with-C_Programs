#include<stdio.h>
int main()
{
	int ar[10],n,i,s=0;
	printf("enter the size of the array : ");
	scanf("%d",&n);
	printf("enter an array elements : ");
	for(i=0;i<n;i++)
	scanf("%d",&ar[i]);
	for(i=0;i<n;i++)
	   s=s+ar[i];
	printf("sum of the array : %d\n",s);
	return 0;
}
