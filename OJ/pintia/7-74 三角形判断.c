#include<stdio.h>
#include<math.h>
double area(double a,double b,double c)
{
	double s=(a+b+c)/2.0,x;
	x=s*(s-a)*(s-b)*(s-c);
	x=sqrt(x);
	return x;
}
int main()
{
	double x1,x2,x3,y1,y2,y3;
	double a=0,b=0,c=0;
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
	a=sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
	b=sqrt((y3-y2)*(y3-y2)+(x3-x2)*(x3-x2));
	c=sqrt((y3-y1)*(y3-y1)+(x3-x1)*(x3-x1));
	if((a+b>c)&&(a+c>b)&&(b+c)>a)
	{
		printf("L = %.2lf, A = %.2lf",a+b+c,area(a,b,c));
	}
	else
	{
		printf("Impossible");
	}
}
