#include<stdio.h>
int main()
{
	int n=0,x=0,a1=0,a2=0,a3=0,amax=0;
	double sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x%3==0)
		{
			if(amax<x)
			{
				amax=x;
				a1++;
			}
		}
		if(x%3==1)
		{
			a2++;
		}
		if(x%3==2)
		{
			a3++;
			sum+=x;
		}
	}
	if(a1!=0)
	printf("%d ",amax);
	else
	printf("NONE ");
	if(a2!=0)
	printf("%d ",a2);
	else
	printf("NONE ");
	if(a3!=0)
	printf("%.1lf",sum*1.0/a3);
	else
	printf("NONE");
}
