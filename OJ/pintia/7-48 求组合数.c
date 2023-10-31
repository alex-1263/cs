#include<stdio.h>
double fact(int n)
{
	if(n==1)
	return 1;
	if(n>1)
	return n*fact(n-1);
}
int main()
{
	int m=0,n=0;
	double x=0;
	scanf("%d %d",&m,&n);
	x=fact(n)/(fact(m)*fact(n-m));
	if(n==m)
	x=1;
	printf("result = %.0lf",x);
    return 0;
}


