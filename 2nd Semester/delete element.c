#include <stdio.h>
int main() 
{
    int i,pos,n;
	int a[5];
	printf("enter the size of array : ");
	scanf("%d",&n);
	printf("enter the number of elements in the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the position of element to be deleted : ");
	scanf("%d",&pos);
	if(pos>=n+1)
	{
		printf("deletion not possible");
	}
	else
	{
	  for(i=pos-1;i<n-1;i++)
	  {
		a[i]=a[i+1];
	  }  	
	
	  printf("Array after deletion : \n");
      for(i=0;i<n-1;i++)
	  {
		
		printf("%d ",a[i]);
	  }
   }

    return 0;
}
