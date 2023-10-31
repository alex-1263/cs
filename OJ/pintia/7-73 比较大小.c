#include<stdio.h>
#include<math.h>
int max(int a,int b)
{
	int max=0;
	if(a>b)
	max=a;
	else 
	max=b;
	return max;
}
int min(int a,int b)
{
	int min=0;
	if(a<b)
	min=a;
	else 
	min=b;
	return min;
}
int mid(int a,int b,int c)
{
	int max=a,mid=b,min=c,x;
	if(min>mid)
	{
		x=min;
		min=mid;
		mid=x;
	}
	if(mid>max)
	{
		x=max;
		max=mid;
		mid=x;
	}
		if(min>mid)
	{
		x=min;
		min=mid;
		mid=x;
	}
	if(mid>max)
	{
		x=max;
		max=mid;
		mid=x;
	}
	return mid;
}
int main()
{
	int a=0,b=0,c=0;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d->%d->%d",min(min(a,b),c),mid(a,b,c),max(max(a,b),c));
}
