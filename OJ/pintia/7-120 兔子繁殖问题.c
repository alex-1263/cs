#include<stdio.h>
int main()
{
	int n=0,t1=1,t2=0,x=0;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		x=t2;
		t2=t1;
		t1+=x;
	}
	printf("%d",t1+t2);
}
/*
	1 1 2 3 5
	0 1 1 2 3
	1 2 3 5 8
*/
