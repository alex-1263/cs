#include<stdio.h>
int main()
{
	int n=0,x=1;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		x=(x+1)*2;
	}
	printf("%d",x);
}
