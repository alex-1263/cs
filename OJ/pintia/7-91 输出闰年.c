#include<stdio.h>
int main()
{
	int y=0,r=0;;
	scanf("%d",&y);
	if(y>=2001&&y<=2100)
	{
		for(int i=2001;i<=y;i++)
		{
			if(i%4==0&&i%100!=0)
			{
				if(r!=0)
				printf("\n");
				printf("%d",i);
				r++;
			}
			if(i%400==0)
			{
				if(r!=0)
				printf("\n");
				printf("%d",i);
				r++;	
			}
		}
		if(r==0)
		{
			printf("None");
		}
	}
	else
	printf("Invalid year!");
}
