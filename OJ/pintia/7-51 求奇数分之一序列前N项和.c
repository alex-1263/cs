#include<stdio.h>
int main()
{
	int n=0;
	double sum=0,x=1,m=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		sum+=x/m;
		m+=2;
	}
	printf("sum = %lf",sum);
	return 0;
}
