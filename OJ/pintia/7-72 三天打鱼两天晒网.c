#include<stdio.h>
int main()
{
	int n=0,x=0;
	scanf("%d",&n);
	x=n%5;
	if(x>0&&x<4)
	printf("Fishing in day %d",n);
	else
	printf("Drying in day %d",n);
}
