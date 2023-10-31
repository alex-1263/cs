#include<stdio.h>
int a(int i)
{
	if(i<=0)
	return 1;
	else if(i>=1&&i<=2)
	return i;
	else
	return a(i-1)+a(i-2);
}
int main()
{
	int x=0;
	while(scanf("%d",&x)!=EOF)
	{
		printf("%d\n",a(x));
	}
	return 0;
}

