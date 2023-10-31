#include<stdio.h>
int main()
{
	double p=0,x=0,n=0,sum=0,z=0,m=1,m1=1;
	scanf("%lf",&n);
	for(int i=0;;i++)
	{
		z*=i;
		if(i==0)
		z=1;
		m*=m1;
		m1+=2;
		x=z*1.0/m;
		sum+=x;
		if(x<n)
		break;
	}
	printf("%.6lf",sum*2);
}
