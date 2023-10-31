#include <stdio.h>
int main()
{
	int n=0,x=0;
	scanf("%d",&n);
	if(n>0)
	x=1;
	if(n==0)
	x=0;
	if(n<0)
	x=-1;
	printf("sign(%d) = %d",n,x);
	return 0;

} 