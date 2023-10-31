#include<stdio.h>
int main()
{
	int n=0;
	long sum=0,x=0;
	scanf("%d",&n);
	for(int i=1;i<n+1;i++)
	{
		x*=10;
		x+=6;
		sum+=x;
	}
	printf("%ld",sum);
}
