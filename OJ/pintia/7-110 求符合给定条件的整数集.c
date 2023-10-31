#include<stdio.h>
int x(int a,int b,int c)
{
	int x=0;
	x=a*100+b*10+c;
	return x;
}
int main()
{
	int n=0,a,b,c,d;
	scanf("%d",&n);
	a=n,b=n+1,c=n+2,d=n+3;
	printf("%d %d %d %d %d %d\n",x(a,b,c),x(a,b,d),x(a,c,b),x(a,c,d),x(a,d,b),x(a,d,c));
	printf("%d %d %d %d %d %d\n",x(b,a,c),x(b,a,d),x(b,c,a),x(b,c,d),x(b,d,a),x(b,d,c));
	printf("%d %d %d %d %d %d\n",x(c,a,b),x(c,a,d),x(c,b,a),x(c,b,d),x(c,d,a),x(c,d,b));
	printf("%d %d %d %d %d %d",x(d,a,b),x(d,a,c),x(d,b,a),x(d,b,c),x(d,c,a),x(d,c,b));
}
