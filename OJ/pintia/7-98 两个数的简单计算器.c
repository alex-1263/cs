#include<stdio.h>
int main()
{
	int a=0,b=0;
	char c=0;
	scanf("%d %c %d",&a,&c,&b);
	if(c=='+')
	{
		printf("%d",a+b);
	}
	else if(c=='-')
	{
		printf("%d",a-b); 
	}
	else if(c=='*')
	{
		printf("%d",a*b);
	}
	else if(c=='/')
	{
		printf("%d",a/b);
	}
	else if(c=='%')
	{
		printf("%d",a%b);
	}
	else
	{
		printf("ERROR");
	}
}
