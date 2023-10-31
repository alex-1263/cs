#include<stdio.h>
int main()
{ 
	double x=0,n=0;
	scanf("%lf",&n);
	if(n!=0)
	{
		x=1/n;
	}
	else
	{
		x=0;
	}
	printf("f(%.1lf) = %.1lf",n,x);
}
