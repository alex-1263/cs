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
	double a=0,b=0,c=0;
	scanf("%lf%lf%lf",&a,&b,&c);
	if((a+b>c)&&(a+c>b)&&(b+c)>a)
	{
		printf("area = %.2lf; perimeter = %.2lf",area(a,b,c),a+b+c);
	}
	else
	{
		printf("These sides do not correspond to a valid triangle");
	}
}
