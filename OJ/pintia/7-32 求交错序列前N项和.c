#include<stdio.h>
int main()
{
	int n=0,flag=0;
	float x1=2,x2=3,sum=1;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++,x1++,x2+=2)
	{
		if(flag==1)
		{
			sum+=x1/x2*1.0;
			flag=0;
		}
		else
		{
			sum-=x1/x2*1.0;
			flag=1;
		}
	}
	printf("%.3f",sum);
}
