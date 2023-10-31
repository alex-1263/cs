#include <stdio.h>
int main()
{
	int a=0,b=0,x=0;
	scanf("%d",&x);
	a=x%16;
	b=x/16*10+a;
	printf("%d",b);
	return 0;

} 