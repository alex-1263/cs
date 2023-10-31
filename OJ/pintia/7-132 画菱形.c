#include<stdio.h>
int main()
{
	int n=0,x=0;
	scanf("%d",&n);
	x=n;
	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			printf(" ");
		}
		for(int j=2*i-1;j>0;j--)
		{
			printf("*");
		}
		printf("\n");
	}
	x=n*2-3;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		printf(" ");
		for(int j=0;j<x;j++)
		printf("*");
		x-=2;
		if(i!=n-1)
		printf("\n");
	}
}
