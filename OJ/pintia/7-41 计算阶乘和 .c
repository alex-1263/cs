#include<stdio.h>
int main()
{
	int n=0,sum=0,x=1;
	scanf("%d",&n);
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<=i;j++)
		{
			x*=j;
		}
		sum+=x;
		x=1;
	}
	printf("%d",sum);
	return 0;
}
