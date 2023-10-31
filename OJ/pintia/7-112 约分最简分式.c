#include<stdio.h>
int main()
{
	int a=0,b=0;
	scanf("%d/%d",&a,&b);
	for(int i=a;i>1;i--)
	{
		if(a%i==0&&b%i==0)
		{
			a/=i;
			b/=i;
		}
	}
	printf("%d/%d",a,b);
}
