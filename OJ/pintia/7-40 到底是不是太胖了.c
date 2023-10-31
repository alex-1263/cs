#include<stdio.h>
int main()
{
	int n=0,w[19],h[19];
	float bw[20],x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&h[i],&w[i]);
		bw[i]=(h[i]-100)*0.9*2;
	}
	for(int i=0;i<n;i++)
	{
			if(bw[i]-w[i]<0.1*bw[i]&&bw[i]-w[i]>-0.1*bw[i])
		{
			printf("You are wan mei!\n");
		}
		else if(bw[i]<w[i])
		{
			printf("You are tai pang le!\n");
		}
		else
		{
			printf("You are tai shou le!\n");
		}
	}
	return 0;
}
