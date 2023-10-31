#include<stdio.h>
int main()
{
	int n=0,i=1,x3=1,x2=1,x1=1;
	scanf("%d",&n);
	while(x3<n)
	{
		i++;
		if(i>=3)
		{
			x3=x1+x2;
		}
		x1=x2;
		x2=x3;
		
	}
	printf("%d",i);
} 

