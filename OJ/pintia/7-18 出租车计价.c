#include<stdio.h>
#include<math.h>
int main()
{
	float l=0,q=0;
	int x=0;
	int s=0;
	scanf("%f %d",&l,&s);
	if(l>=0){
		if(l<=3) q=10;
		else if(l<=10) q=10+(l-3)*2;
		else q=24+(l-10)*3;
	}
	if(s>=5)
	{
		q+=(s/5)*2;
		x=(int)q;
	}
	x=(int)q;
	if(q-0.5>=x)
		q=x+1;
	else
		q=x;
	printf("%.0f",q);
	return 0;
}
