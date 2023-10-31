#include<stdio.h>
int su(int n)
{
	if(n==1)
		{
			return 0;
		}
		if(n==2)
		{
			return 2;
		}
	for(int j=2;j<n;j++)
	{
		if(n%j==0)
		{
			return 0;
			break;
		}	
	}
	return n;
}
int main()
{
	int m=0,n=0,sum=0,x=0;
	scanf("%d %d",&m,&n);
	for(int i=m;i<n+1;i++)
	{
		if(n==m)
		{
			if(su(i)!=0)
			{
				sum+=su(i);
				x++;
			}
			break;
		}
		sum+=su(i);
		if(su(i)!=0)
		x++;
	}
	printf("%d %d",x,sum);
}
