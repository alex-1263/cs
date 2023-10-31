#include<stdio.h>
int main()
{
	int a=0,b=0;
	double x=0;
	scanf("%d %d",&a,&b);
	x=a*1.0/b;
	if(b==0)
	printf("%d/%d=Error",a,b);
	else if(b>0)
	printf("%d/%d=%.2f",a,b,x);
	else
	printf("%d/(%d)=%.2f",a,b,x);
}
