#include<stdio.h>
int main()
{
	int n=0,y=0,r=0,run=0,x=0;
	scanf("%d/%d/%d",&n,&y,&r);
	if(n%400==0)
	{
		run=1;
	}
	if(n%4==0&&n%100!=0)
	{
		run=1;
	}
	if(run==1)
	{
		if(y==1) x=r;
		if(y==2) x=r+31;
		if(y==3) x=r+60;
		if(y==4) x=r+91;
		if(y==5) x=r+121;
		if(y==6) x=r+152;
		if(y==7) x=r+182;
		if(y==8) x=r+213;
		if(y==9) x=r+244;
		if(y==10) x=r+274;
		if(y==11) x=r+305;
		if(y==12) x=r+335;
	}
		else
	{
		if(y==1) x=r;
		if(y==2) x=r+31;
		if(y==3) x=r+60;
		if(y==4) x=r+91;
		if(y==5) x=r+121;
		if(y==6) x=r+152;
		if(y==7) x=r+182;
		if(y==8) x=r+213;
		if(y==9) x=r+244;
		if(y==10) x=r+274;
		if(y==11) x=r+305;
		if(y==12) x=r+335;
		x-=1;
	}
	printf("%d",x);
}
