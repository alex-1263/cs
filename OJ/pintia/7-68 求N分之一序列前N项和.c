#include<stdio.h>
int main()
{
	double sum=0,x=1;
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		sum+=1/x;
		x++;
	}
	printf("sum = %.6lf",sum);
}
