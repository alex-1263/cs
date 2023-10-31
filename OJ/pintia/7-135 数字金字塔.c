#include<stdio.h>
int main()
{
	int n=0,i=0,j=0,k=38;
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		for(j=0;j<k;j++)
		{
			printf(" ");
		}
		k--;
		for(j=1;j<i+1;j++)
		{
			printf("%d",j);
		}
		for(j=i-1;j>0;j--)
		{
			printf("%d",j);
		}
		if(i!=n)
		printf("\n");
	}
}
