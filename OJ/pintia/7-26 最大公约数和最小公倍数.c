#include<stdio.h>
int main()
{
	int m=0,n=0,y=1000,b=0,flag1=0,flag2=0;
	scanf("%d %d",&m,&n);
	while(flag1==0)
	{
		if(m%y==0&&n%y==0)
		{
			flag1=1;
		} 
		if(flag1==0)
		{
			y--;
		}
	}
	while(flag2==0)
	{
		if(flag2==0)
		{
			b++;
		}
		if(b%m==0&&b%n==0)
		{
			flag2=1;
		}
	}
	printf("%d %d",y,b);
	return 0;
} 
