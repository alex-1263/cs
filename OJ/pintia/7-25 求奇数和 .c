#include<stdio.h>
int main()
{
	int sum=0,n=0;
	n++;
	while(n>0)
	{
		scanf("%d",&n);
		if(n%2==1&&n>0)
		{
			sum+=n;
		}
	}
	printf("%d",sum);
	return 0;
}

