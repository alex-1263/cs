#include<stdio.h>
int main()
{
	int l=0,u=0,x=0,flag=1;
	double c=0;
	scanf("%d %d",&l,&u);
	x=l;
	if(x>u)
	printf("Invalid.");

	for(;x<=u;x+=2)
	{
		if(x>u)
		{
			printf("Invalid.");
		}
		if(x==l)
		printf("fahr celsius\n");
		c=5*(x-32.0)/9;
		printf("%d%6.1lf\n",x,c);
	}
}
