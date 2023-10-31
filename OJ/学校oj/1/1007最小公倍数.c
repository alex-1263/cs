#include<stdio.h>
int main()
{
	long a=0,b=0,x=0,min=0;
	while(scanf("%ld %ld",&a,&b)!=EOF)
	{
		x=0;
		if(a>b)
		min=b;
		else
		min=a;
		for(int i=1;i<min+1;i++)
		{
			if(a%i==0&&b%i==0)
			{
				if(i>x)
				x=i;
			}
		}
		printf("最小公倍数：%ld\n最大公约数：%ld\n",a*b/x,x);
	}
	return 0;
}
