#include<stdio.h>
int main()
{
	char xb;
	double g;
	int n=0;
	scanf("%d",&n);
	int i=0;
	while(n!=0)
	{
		scanf("\n%c %lf",&xb,&g);
		double result;
		if(xb == 'M')
		{
			result = g / 1.09;
			printf("%.2f\n",result);
		}
		else
		{
			result = g * 1.09;
			printf("%.2f\n",result);
		}
		n--;
	}
}
