#include<stdio.h>
int a(int n)
{
	if(n==1)
	return 0;
	if(n==2)
	return 1;
	if(n==3)
	return 1;
	if(n>3)
	return a(n-1)+a(n-2);
}
int main()
{
	int n=0;
	scanf("%d",&n);
	printf("%d",a(n));
}
