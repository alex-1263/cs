#include<stdio.h>
int main()
{
	double n=0,sum=0,x;
	int i=0;
	while(1)
	{
		scanf("%lf",&n);
		if(n<0)
		break;
		sum+=n;
		i++;
	}
	x=sum*1.0/i;
	if(n<0&&i==0)
	printf("None");
	else
	printf("%.2lf",x);
}
