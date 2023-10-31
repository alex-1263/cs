#include <stdio.h>
int main()
{
	int d,t;
	scanf("%d",&t);
	d=(t+2)%7;
	if(d!=0)
	printf("%d",d);
	else
	printf("7");
} 