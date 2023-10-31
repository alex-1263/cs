#include<stdio.h>
int main()
{
	int x=0,i=1,n=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==250&&x==0)
		{
			printf("%d",i);
			x++;
		}
		i++;
	}
}
