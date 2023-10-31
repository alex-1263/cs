#include<stdio.h>
int main()
{
	double z1=2,n=0,z2=3,x=0,m1=1,m2=2,he=2;
	scanf("%lf",&n);
	if(n>1)
	{
		for(int i=1;i<n;i++)
		{
			he+=z2/m2*1.0;
			x=z2;
			z2+=z1;
			z1=x;
			x=m2;
			m2+=m1;
			m1=x;
		}
	}
	printf("%.2lf",he);
}
