#include<stdio.h>
int main()
{
	int n=0,i,j,k,f=0;
	scanf("%d",&n);
	for(i=0;i<=n/3+1;i++)
	{
		for(j=0;j<=n/2+1;j++)
		{
			for(k=0;k<=2*n;k+=2)
			{
				if((i+j+k==n)&&(i*3+j*2+k/2==n))
				{
					if(f!=0)
					printf("\n");
					printf("men = %d, women = %d, child = %d",i,j,k);
					f++;
				}
			}
		}
	}
	if(f==0)
	{
		printf("None");
	}
}
