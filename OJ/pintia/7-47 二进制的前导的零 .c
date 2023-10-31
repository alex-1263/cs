#include<stdio.h>
int main()
{
	int x=2,i=1,n=0;
	scanf("%d",&n);
	for(;x<n;i++)
	{
		x*=2;
		if(x==n)
		{
			i++;
		}
	}
	if(n==0)
	{
		i=0;
	}
	if(n<0)
	{
		i=32;
	}
	printf("%d",32-i);
	return 0;
}

