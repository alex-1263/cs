#include<stdio.h>
int main()
{
	int n=0,x=0;
	scanf("%d",&x);
	for(int i=20;i>0;i--)
	{
		for(int j=50;j>0;j--)
		{
			for(int k=100;k>0;k--)
			{
				if(i*5+j*2+k==x)
				{
					printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",i,j,k,j+k+i);
					n++;
				}
			}
		}
	}
	printf("count = %d",n);
}
