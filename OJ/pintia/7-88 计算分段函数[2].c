#include<stdio.h>
#include<math.h>
int main()
{
	double n=0,x=0;
	scanf("%lf",&n);
	if(n>=0)
	{
		x=sqrt(n);
	}
	else
	{
		x=pow(n+1,2)+2.0*n+1/n;
	}
	printf("f(%.2lf) = %.2lf",n,x);
}
