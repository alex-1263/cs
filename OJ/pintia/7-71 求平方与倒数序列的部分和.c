#include<stdio.h>
int main()
{
	double sum=0;
	int m=0,n=0;
	scanf("%d%d",&m,&n);
	for(int i=m;i<n+1;i++)
	{
		sum+=i*i;
		sum+=1.0/i;
	}
	printf("sum = %.6lf",sum);
}
