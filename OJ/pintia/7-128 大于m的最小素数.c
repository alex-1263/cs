#include<stdio.h>
int main()
{
	int m=0,x=0;
	scanf("%d",&m);
	for(int i=m+1;;i++)
	{
		for(int j=i-1;j>1;j--)
		{
			if(i%j==0)
			{
				x++;
				break;
			}
		}
		if(x==0)
		{
			printf("%d",i);
			break;
		}
		else
		x=0;
	}
}
