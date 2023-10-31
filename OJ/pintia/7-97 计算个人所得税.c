#include<stdio.h>
int main()
{
	double s=0,q=0;
	scanf("%lf",&q);
	if(q<=1600)
	{
		s=0;
	}
	else if(q<=2500)
	{
		s=0.05*(q-1600);
	}
	else if(q<=3500)
	{
		s=0.1*(q-1600);
	}
	else if(q<=4500)
	{
		s=0.15*(q-1600);
	}
	else
	{
		s=0.2*(q-1600);
	}
	printf("%.2lf",s);
}
