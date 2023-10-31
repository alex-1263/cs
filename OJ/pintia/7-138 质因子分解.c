#include<stdio.h>
long zhz(long n)
{
	int x=0;
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			printf("%d*",i);
			n=n/i;
			i=1;
		}
	}
	printf("%d",n);
}
int main()
{
	long x=0;
	scanf("%ld",&x);
	printf("%ld=",x);
	zhz(x);
}
