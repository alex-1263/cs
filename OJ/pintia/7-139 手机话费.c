#include<stdio.h>
int main()
{
	int m=0,k=0,t=0,z=0;
	scanf("%d %d",&m,&k);
	while(1)
	{
		m--;
		t++;
		z++;
		if(z==k)
		{
			m++;
			z=0;
		}
		if(m==0)
		break;
	}
	printf("%d",t);
}
