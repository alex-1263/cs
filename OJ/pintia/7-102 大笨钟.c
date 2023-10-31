#include<stdio.h>
int main()
{
	int h=0,m=0,n=0;
	scanf("%d:%d",&h,&m);
	if(h>=0&&h<11)
	{
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
	}
	else if(h==12&&m==0)
	{
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
	}
	else if(h>=12&&h<=23)
	{
		n=h-12;
		if(m>0)
		n++;
		for(int i=0;i<n;i++)
		{
			printf("Dang");
		}
	}
	else if(h==24)
	{
		h=h-24;
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
	}
}
