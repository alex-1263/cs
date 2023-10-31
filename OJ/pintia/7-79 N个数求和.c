#include<stdio.h>
long min(long a,long b)
{
	long min;
	if(a>b)
	min=b;
	else
	min=a;
	return min;
}
int main()
{
	long n=0,a[100][2]={0},x1=0,x2=0,d=0;
	scanf("%ld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%ld/%ld",&a[i][0],&a[i][1]);
		if(i==0)
		{
			x1=a[i][0];
			x2=a[i][1];
		}
		else
		{
			x1=x1*a[i][1]+a[i][0]*x2;
			x2*=a[i][1];
		}
		if(x1>0)
		{
			for(int j=min(x1,x2);j>1;j--)
			{
				if(x2%j==0&&x1%j==0)
				{
					x1/=j;
					x2/=j;
				}	
			} 
		}
		if(x1<0)
		{
			x1=-x1;
			for(int j=min(x1,x2);j>1;j--)
			{
				if(x2%j==0&&x1%j==0)
				{
					x1/=j;
					x2/=j;
				}	
			}
			x1=-x1;
		}
	}
	d=x1/x2;
	x1=x1%x2;
	if(d==0&&x1==0)
	printf("0");
	else if(d==0)
	printf("%ld/%ld",x1,x2);
	else if(x1==0)
	printf("%ld",d);
	else
	printf("%ld %ld/%ld",d,x1,x2);
}
