#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	for(int i=1;i<n+1;i++)
	{
		if(i!=1)
		printf(" ");
		printf("%d",i);
	}
	for(int i=n-1;i>0;i--)
	{
		printf(" %d",i);
	}
}
