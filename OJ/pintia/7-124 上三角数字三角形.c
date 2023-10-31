#include<stdio.h>
int main()
{
	int n=0,i=1,j=0;
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		for(int k=0;k<n-j;k++)
		{
			printf("%4d",i);
			i++;
		}
		if(j!=n-1)
		printf("\n"); 
	}
}
