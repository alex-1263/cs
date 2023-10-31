#include<stdio.h>
int main()
{
	int n=0;
	double sum=0,z=1.0,m=1.0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			sum+=z/m;
		}
		else
		{
			sum-=z/m;
		}
		m+=3;
	}
	printf("sum = %.3lf",sum);
	return 0;
}
