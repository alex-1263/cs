#include<stdio.h>
int main()
{
	int n=0,min=0,x=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i==0)
		min=x;
		if(min>x)
		min=x;
	}
	printf("min = %d",min);
}
