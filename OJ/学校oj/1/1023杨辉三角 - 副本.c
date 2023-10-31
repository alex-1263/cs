#include<stdio.h>
int main()
{
	long n=0,a[31][31],i,j,x;
	while(scanf("%ld",&n)!=EOF)
	{
		for(i=0;i<31;i++)
		{
			for(j=0;j<31;j++)
			{
				a[i][j]=0;
			}
		}
		a[0][0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(j!=0)
				printf(" ");
				a[i][j] = a[i-1][j-1]+a[i-1][j];
				printf("%ld",a[i][j]);
			}
			printf("\n");
		}
	}
}
