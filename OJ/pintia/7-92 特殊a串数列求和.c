#include<stdio.h>
long long xn(int x,int n)
{
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum*=10;
		sum+=x;
	}
	return sum;
}
int main()
{
	long long sum=0;
	int x=0,n=0;
	scanf("%d %d",&x,&n);
	for(int i=1;i<n+1;i++)
	{
		sum+=xn(x,i);
	}
	printf("s = %lld",sum);
}
