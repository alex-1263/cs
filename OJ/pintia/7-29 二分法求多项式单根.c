#include<stdio.h>
double a3=0,a2=0,a1=0,a0=0,a=0,b=0,c=0;
double f(double x) {
    return a3*x*x*x + a2*x*x + a1*x + a0;
}
int main()
{
	scanf("%lf %lf %lf %lf",&a3,&a2,&a1,&a0);
	scanf("%lf %lf",&a,&b);
	while(b-a>=0.01)
	{
			if(f((a+b)/2)==0)
			{
				c=(a+b)/2;
				break;
			}
			if(f(a) == 0)
		{
			c=a;
			break;
		}
		if(f(b) == 0)
		{
			c=b;
			break;
		}
				if(f((a+b)/2)*f(a)>=0)
				{
					a=(a+b)/2;
				}
				else
				{
					b=(a+b)/2;
				}
	}
	if(b-a<0.01)
	{
		c=(a+b)/2;
	}
	printf("%.2lf",c);
	return 0;
}

