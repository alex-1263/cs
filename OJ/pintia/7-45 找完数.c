#include<stdio.h>
int main()
{
	int m=0,n=0,sum=0,j=0,i=0,x=0;
	
	scanf("%d %d",&m,&n);
	
	for(i=m;i<=n;i++)
	{
		sum=1;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			sum+=j;
		}
		if(sum==i)
		{
			x++; 
			printf("%d = 1",i);
			for(j=2,sum=1;j<i;j++)
			{	
				if(i%j==0)
				{
				sum+=j;
				printf(" + %d",j);
				}
			}
			printf("\n");
		}
	}
	if(x==0)
	printf("None");
	return 0;
}
