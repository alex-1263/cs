#include<stdio.h>
int main()
{
	int h1=0,h2=0,m1=0,m2=0,h,m;
	scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
	h=h2-h1;
	m=m2-m1;
	if(m<0)
	{
		h--;
		m+=60;
	}
	printf("%d %d",h,m);
}
