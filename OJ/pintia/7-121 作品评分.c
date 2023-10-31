#include<stdio.h>
int main()
{
	int n=0;
	double sum=0,x=0,max=0,min=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&x);
		if(i==0)
		min=x;
		if(x>max)
		max=x;
		if(min>x)
		min=x;
		sum+=x;
	}
	printf("%.2lf",(sum-max-min)/(n-2));
}
