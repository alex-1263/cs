#include<stdio.h>
int main()
{
	int n=0,sum=0,i=1;
	char x,a;
	do
	{
		scanf("%d%c",&n,&x);
		if(i==1){
		sum=n;
		a='*';
		n=1;
		}
		if(a=='*')
		{	
			sum*=n;
			if(x=='=')	printf("%d",sum);
		}
		else if(a=='/')
		{
			if(n==0)
			{
			x='=';
			printf("ERROR"); 
			}
			else
			{
			sum/=n;
			if(x=='=')	printf("%d",sum);
			}
		}
		else if(a=='+')
		{
			sum+=n;
			if(x=='=')	printf("%d",sum);
		}
		else if(a=='-')
		{
			sum-=n;
			if(x=='=')	printf("%d",sum);
		}
		
		else
		{
		printf("ERROR");
		x='=';
		}
		i++;
		a=x;
	}
	while(x!='=');
	return 0;
}
