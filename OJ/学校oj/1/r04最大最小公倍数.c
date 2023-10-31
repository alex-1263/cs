#include<stdio.h>
int main()
{
	int n=0,x=1157520;
	while(scanf("%d",&n)!=EOF)
	{
		x=1157520;
		if(n%2==1)
		{
			x=n*(n-1)*(n-2);
		}
		if(n%2==0)
		{
			if(n%3==0)
			{
				x=(n-1)*(n-2)*(n-3);
			}
			else
			{
				x=n*(n-1)*(n-3);
			}
		}
		printf("%d\n",x);
	}
	return 0;
}
