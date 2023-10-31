#include<stdio.h>
int main()
{
	int y=0,w=0;
	double x=0;
	scanf("%d %d",&y,&w);
	if(y<5)
	{
		if(w<=40)
		x=w*30;
		else 
		x=40*30+(w-40)*30*1.5;
	}
	else
	{
		if(w<=40)
		x=w*50;
		else 
		x=40*50+(w-40)*50*1.5;
	}
	printf("%.2lf",x);
}
