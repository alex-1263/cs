#include<stdio.h>
#include<math.h>
int main()
{
	double sum=1.0,x=0,fz=1,fm=1;
	float x1=0;
	scanf("%lf",&x);
	for(int i=1;;i++)
	{
		fm=fm*i;
		fz=pow(x,i);
		sum+=fz/fm;
		if(fz/fm<0.00001)
		break;
	}
	printf("%.4lf",sum);
	return 0;
}
