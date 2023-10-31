#include<stdio.h>
int main()
{
	int n=0,j=0;
	scanf("%d",&n);
	for(int x=1;x<=n;x++)
	{
		for(int y=x;y<=n;y++)
		{
			if(x*x+y*y==n)
			{
				if(j!=0)
				printf("\n");
				printf("%d %d",x,y);
				j++;
			}
		}
	}
	if(j==0)
	printf("No Solution");
}
