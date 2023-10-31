#include<stdio.h>
int main()
{
		int x=0;
		while(1)
		{
			x++;
			if(x%5==1)
			{
				if(x%6==5)
				{
					if(x%7==4)
					{
						if(x%11==10)
						{
							break;
						}
					}
				}
			}
		}
		printf("%d",x);
}
