#include<stdio.h>
int sum(int i)
{
	int n,he=0,x=10000;
	for(n=0;n<5;n++)
	{
		he+=i/x;
		i=i%x;
		x/=10;
	}
	return he;
}
int main()
{
	int n[100],i=1,x1=0,x2=0,flag=0;
	for(int i=0;i<100;i++)
	n[i]=0;
	scanf("%d",&n[i-1]);
	if(n[i-1]==13)
	{
		printf("1:13");
		flag=1;
	}
	while(flag==0)
	{
		n[i]=sum(n[i-1])*3+1;
		x2=x1;
		x1=n[i];
		printf("%d:%d\n",i,n[i]);
		i++;
		if(x1==x2)
		{
			break;
		}
	}
}
