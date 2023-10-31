#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	if(n%2==0)
	n--;
	for(int i=1;i<=n;i+=2)
	{
		if(i!=1)
		printf(" ");
		printf("%d",i);
	}
}
