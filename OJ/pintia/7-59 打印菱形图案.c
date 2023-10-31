#include<stdio.h>
int max(int a,int b)
{
	int max;
	if(a>b)
	max=a;
	else
	max=b;
	return max;
}
int min(int a,int b)
{
	int min;
	if(a>b)
	min = b;
	else
	min =a;
	return min;
}
int main()
{
	int n=0,i=0,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=min(i+1,(n+1)/2);j<max(i+1,(n+1)/2);j++)
		{
			printf("  ");
		}
		if(i+1<=(n+1)/2)
		{
			for(j=0;j<2*i+1;j++)
			{
				printf("* ");	
			}
		}
		if(i+1>(n+1)/2)
		{
			for(j=0;j<(n-i)*2-1;j++)
			{
				printf("* ");
			}
		}
		printf("\n");
	}
	return 0;
}
