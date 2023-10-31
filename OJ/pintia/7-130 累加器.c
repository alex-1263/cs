#include<stdio.h>
int main()
{
	int n=0,x=0;
	long sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		sum+=x;
	}
	printf("%ld",sum);
}
