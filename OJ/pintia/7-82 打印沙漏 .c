#include<stdio.h>
int main()
{
	int n=0,a=0,a1=0,a2=0,i=0;
	char x=0;
	scanf("%d %c",&n,&x);
	for(a1=1;a*2-1<=n;)
	{
		a+=a1;
		a1+=2;
		i++;
	}
	i--;
	a1-=2;
	a-=a1;
	a1-=2;
	a2=a1;
	for(int j=0;j<i;j++)
	{
		for(int k=j;k>0;k--)
		{
			printf(" ");
		}
		for(int k=a2;k>0;k--)
		{
			printf("%c",x);
		}
		printf("\n");
		a2-=2;
	}
	a2=3;
	i--;
	for(int j=i;j>0;j--)
	{
		for(int k=j;k>1;k--)
		{
			printf(" ");
		}
		for(int k=a2;k>0;k--)
		{
			printf("%c",x);
		}
		printf("\n");
		a2+=2;
	}
	printf("%d",n-a*2+1);
}

