#include<stdio.h>
double jc(int n)
{
	if(n==0)
	return 1;
	else
	return n*jc(n-1);
}
int main()
{
	int n=0,i;
	double sum=0;
	scanf("%d",&n);
	for(i=0;i<n+1;i++)
	{
		sum+=1.0/jc(i);
	}
	printf("%.8lf",sum);
	return 0;
}
