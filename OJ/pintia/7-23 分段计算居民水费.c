#include<stdio.h>
int main()
{
	float x=0,y=0;
	scanf("%f",&x);
	if(x<=15&&x>=0)
	{
		y=4*x/3;
	}
	else 
	{
		y=2.5*(x)-17.5;
	}
	printf("%.2f",y);
	return 0;
} 
