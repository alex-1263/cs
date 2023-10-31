#include<stdio.h>
int main()
{
	int n=0,i=0,j=1,k=0,x=0,x1=0;
	scanf("%d",&n);
	for(i=n;i>0;i--)
	{
		for(k=i,x=j,x1=n;k>0;k--)
		{
			printf("%4d",x);
			x+=x1;
			x1--;
		}
		if(i!=1)
		printf("\n");
		j++;
	}
}
