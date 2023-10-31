#include<stdio.h>
int x(int m,int n)
{
	if(m<n)
	return 0;
	if(n==0)
	return 1;
	return x(m-1,n)+x(m,n-1);
}
int main()
{
	int m=0,n=0;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		printf("%d\n",x(m,n));
	}
}
