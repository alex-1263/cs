#include<stdio.h>
int main()
{
	int a=0,b=0,c=0;
	char x=0;
	scanf("%d %d %d",&a,&b,&c);
	if(a==b)
	{
		x='C';
	}
	else if(a==c)
	{
		x='B';
	} 
	else 
	{
		x='A';
	}
	printf("%c",x);
}
