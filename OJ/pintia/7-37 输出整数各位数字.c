#include<stdio.h>
int main()
{
	long n=0,x=0,i=0,chu=1,w=0,a=0;
	scanf("%ld",&n);
	if(n==0)
	printf("0 ");
	for(i=0,x=n;x>0;i++)
	{
		x/=10;
	}
	w=i;
	for(i=1;i<w;i++)
	{
		chu*=10;	
	}
	for(i=0;i<w;i++)
	{
		a=n/chu;
		n%=chu;
		chu/=10;
		printf("%ld ",a);
	}
}
