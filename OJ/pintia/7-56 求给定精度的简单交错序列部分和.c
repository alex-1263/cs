#include<stdio.h>
int main()
{
	double x=0,sum=1.0,z=1.0,m=4.0;
	scanf("%lf",&x);
	for(int i=0;;i++)
	{
		if(sum<=x)
		break;
		if(i%2==0)
		{
			sum-=z/m;
		}
		else
		{
			sum+=z/m;
		}
		if(z/m<=x)
		break;
		m+=3;
	}
	printf("sum = %.6lf",sum);
	return 0;
}
