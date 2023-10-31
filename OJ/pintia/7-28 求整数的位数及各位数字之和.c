#include<stdio.h>
int main()
{
	long long n=0,i=0,sum=0,j=0;
	scanf("%lld",&n);
	i++;
	while(i<=10)
	{	
		sum+=n%10;
		if(n>0)	
		{
			j++;
			n/=10;
		}
		i++;
	}
	printf("%d %d",j,sum);
	return 0;
}
