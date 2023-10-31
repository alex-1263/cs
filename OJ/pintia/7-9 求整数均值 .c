#include <stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0,sum=0;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	sum=a+b+c+d;
	printf("Sum = %d; Average = %.1f",sum,sum/4.0);
	return 0;
}