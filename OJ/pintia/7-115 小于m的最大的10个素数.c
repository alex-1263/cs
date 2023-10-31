#include<stdio.h>
int main()
{
	int m=0,n=0;
	scanf("%d",&m);
	for(int i=m-1;;i--)
	{
		for(int j=i-1;;j--)
		{
			if(j==1)
			{
				printf("%6d",i);
				n++;
			}
			if(i%j==0)
			break;
		}
		if(n==10)
		break;
	}
}
