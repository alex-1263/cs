#include<stdio.h>
int main()
{
	float a[5]={0,3.00,2.50,4.10,10.20};
	int n=0;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&n);
		if(i==0)
		printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
		if(n==0)
		break;
		else if(n>=1&&n<=4)
		{
			if(i!=0)
			{
				printf("\n");
			}
			printf("price = %.2f",a[n]);
		}
		else
		{
			if(i!=0)
			{
				printf("\n");
			}
				printf("price = %.2f",a[0]);
		}
	}
	return 0;
}
