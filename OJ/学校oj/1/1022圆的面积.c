#include<stdio.h>
#include<math.h>
int main()
{
	double const pi =atan(1.0)*4;
	double x=0;
	int n=0;
	while(scanf("%d",&n)!=EOF)
	{
		x=pi*n*n;
		printf("%.7lf\n",x);
	}
}
