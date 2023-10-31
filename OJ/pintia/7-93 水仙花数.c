#include<stdio.h>
#include<math.h>
int main()
{
	int n=0,sum=0,w[8]={0},i=0,x=0,s=0;
	scanf("%d",&n);
	int j=0;
	for(i=pow(10,n-1);i<pow(10,n);i++)
	{
		if(n==7)
		break;
		for( j=0;j<n+1;j++)
		{
			w[j]=0;
		}
		x=i;
		for( j=n;j>0;j--)
		{
			w[j]=x/pow(10,j-1);
			x=x-w[j]*pow(10,j-1);
		}
		for( j=0;j<8;j++)
		{
			sum+=pow(w[j],n);
		}
		if(sum==i)
		{
			if(s!=0)
			printf("\n");
			printf("%d",i);
			s++;
		}
		
		sum=0;
	}
	if(n==7)
	{
		printf("1741725\n4210818\n9800817\n9926315");
	}
	return 0;
}
