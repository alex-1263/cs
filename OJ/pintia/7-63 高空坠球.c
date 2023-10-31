#include<stdio.h>
int main()
{
	long h=0,n=0;
	double t=0,s=0;
	scanf("%ld %ld",&h,&n);
	t=h;
	s=h;
	for(int i=1;i<n;i++)
	{
		s+=t;
		t/=2;
	}
	if(n>0)
	printf("%.1lf %.1lf",s,t/2);
	else
	printf("0.0 0.0");
	return 0;
}
