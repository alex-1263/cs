#include<stdio.h>
int main()
{
	int n=0,x=0,i=0,j=0,k=0,z=0;
	scanf("%d",&n);
	for(i=1;i<21;i++)
	{
		if(z>=n)
				{
					break;
				}
		for(j=1;j<50;j++)
		{
			if(z>=n)
				{
					break;
				}
			for(k=1;k<100;k++)
			{
				if(z>=n)
				{
					break;
				}
				if(i+k+j==100&&i*5+j*2+k==150)
				{
					if(z!=0)
					printf("\n");
					printf("%d %d %d",i,j,k);
					z++;
				}
			}
		}
	}
}
