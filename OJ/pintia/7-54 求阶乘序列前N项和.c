#include<stdio.h>
int jc(int n)
{
	if(n==1)
	return 1;
	if(n>1)
	return n*jc(n-1);
}
int main()
{
	int n=0,sum=0;
	scanf("%d",&n);
	for(int i=1;i<n+1;i++)
	{
		sum+=jc(i);
	}
	printf("%d",sum);
	return 0;
}
