#include<stdio.h>
int main()
{
	int i=0,j=0,n=0;
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<i+1;j++)
		{
			printf("%d*%d=%-4d",j,i,i*j);
		}
		if(i!=n)
		printf("\n");
	}
}

