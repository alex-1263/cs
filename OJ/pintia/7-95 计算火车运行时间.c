#include<stdio.h>
int main()
{
	int x1=0,x2=0,h1=0,h2=0,m1=0,m2=0;
	scanf("%d %d",&x1,&x2);
	h1=x1/100;
	h2=x2/100;
	m1=x1%100;
	m2=x2%100;
	h2=h2-h1;
	m2=m2-m1;
	if(m2<0)
	{
		h2--;
		m2+=60;
	}
	printf("%02d:%02d",h2,m2);
}
