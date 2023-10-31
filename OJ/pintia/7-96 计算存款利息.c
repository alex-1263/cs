#include<stdio.h>
#include<math.h>
int main()
{
	double m=0,y=0,r=0,i=0;
	scanf("%lf %lf %lf",&m,&y,&r);
	i=m*(pow(1+r,y)-1);
	printf("interest = %.2lf",i);
}
