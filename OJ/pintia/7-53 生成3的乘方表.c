#include<stdio.h>
int main()
{
	int n=0,i;
	long x=1;
	scanf("%d",&n);
	for(i=0;i<n+1;i++)
	{
		printf("pow(3,%d) = %ld\n",i,x);
		x*=3;
	}
	return 0;
}
