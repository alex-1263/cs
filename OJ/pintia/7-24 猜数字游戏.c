#include<stdio.h>
int main()
{
	int a=0,b=0,i=0,x=0,c=0;
	scanf("%d %d",&a,&b);
	while(i<b)
	{
		scanf("%d",&x);
		if(x==a)
		{
			if(i==0) printf("Bingo!"),i=b;
			else if(i<=2) printf("Lucky You!"),i=b;
			else printf("Good Guess!\n"),i=b;
		}
		if(x>a)
		{
			printf("Too big\n");
			c++;
		}
		if(x<a&&x>0)
		{
			printf("Too small\n");
			c++;
		}
		i++;
		if(x<0)
		{
			c=b;
			i=b;
		}
	}
	if(c==b)
	{
		printf("Game Over");
	}
}
