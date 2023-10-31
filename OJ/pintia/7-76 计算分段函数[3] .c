#include<stdio.h>
int main()
{
	double n=0;
	scanf("%lf",&n);
	if(n==10)
	printf("f(%.1lf) = %.1f",n,1/n);
	else
	printf("f(%.1lf) = %.1lf",n,n);
}
