#include<stdio.h>
int max(int a,int b)
{
	int max;
	if(a>=b)
		max=a;
	else
		max=b;
	return max;
}
int min(int a,int b)
{
	int min;
	if(a>=b)
		min=b;
	else
		min=a;
	return min;
}
int main()
{
	int n=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,max1=0,min1=0,i=1,bw=0,sw=0,gw=0;
	scanf("%d",&n);
	do
	{
		bw=n/100;
		sw=(n/10)%10;
		gw=n%10;
		a1=n; a2=bw*100+gw*10+sw;
		a3=gw*100+bw*10+sw; a4=gw*100+sw*10+bw;
		a5=sw*100+bw*10+gw; a6=sw*100+gw*10+bw;
		max1=max(max(max(a1,a2),a3),max(max(a4,a5),a6));
		min1=min(min(min(a1,a2),a3),min(min(a4,a5),a6));
		n=max1-min1;
		printf("%d: %d - %d = %d\n",i,max1,min1,n);
		if((gw==bw)&&(sw==bw))
		{
			break;
		}
		i++;
	}
	while(n!=495);
}
