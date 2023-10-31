#include<stdio.h>
int main()
{
	long n=0,i=0;
	scanf("%ld",&n);
	for(i=0;;i++)
	{
			if(n==1)
		break;
		if(n%2==1)
		n=3*n+1;
		else
		n/=2;
	}
	printf("%d",i);
}
