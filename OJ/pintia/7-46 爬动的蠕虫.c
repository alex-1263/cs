#include<stdio.h>
int main()
{
	int n=0,u=0,d=0,t=0,x=0;
	scanf("%d %d %d",&n,&u,&d);
	for(t=1;;t++)
	{
		x+=u;
		if(x>=n)
		{
			break;
		}
		t++;
		x-=d;
	}
	printf("%d",t);
	return 0;
}
