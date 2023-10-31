#include<stdio.h>
int main()
{
	int n=0,i=0,j=0,w=0,x=0,flag=0;
	scanf("%d",&n);
	if(n<0)
	{
		printf("fu ");
		n=-n;
	}
	for (w=1,j=n;n>=0;w++)
	{
		j=j/10;
		if(j==0)
		break;
	}
	for(i=1,x=1;i<w;i++)
	{
		x=x*10;
	}
	for(i=1;i<=w;i++,flag++)
	{	
		if(flag>0)
		printf(" ");
		j=n/x;
		n=n%x;
		x=x/10;
		if(j==0)
		printf("ling");
		if(j==1)
		printf("yi");
		if(j==2)
		printf("er");
		if(j==3)
		printf("san");
		if(j==4)
		printf("si");
		if(j==5)
		printf("wu");
		if(j==6)
		printf("liu");
		if(j==7)
		printf("qi");
		if(j==8)
		printf("ba");
		if(j==9)
		printf("jiu");
	}
}
