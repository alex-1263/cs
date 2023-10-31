#include<stdio.h>
int main()
{
	float f=0.53,x=0,q;
	scanf("%f",&x);
	if(x>0)
	{
		if(x<50)
		{
			q=x*f;
		}
		else
		{
			q=50*f;
			x-=50;
			f+=0.05;
			q+=x*f;
		}
		printf("cost = %.2f",q);
	}
	else
	printf("Invalid Value!");
}
