#include<stdio.h>
int main()
{
	long n=0,a[30],b[30],i,j,x;
	while(scanf("%ld",&n)!=EOF)
	{
		for(i=0;i<30;i++)
		{
		a[i]=1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<i+1;j++)
			{
				printf("%ld ",a[j]);
				b[j]=a[j];
				a[j]=b[j-1]+b[j];
			}
			printf("\n");
		}
	}
}

