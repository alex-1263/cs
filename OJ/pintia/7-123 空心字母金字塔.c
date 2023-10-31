#include<stdio.h>
int main()
{
	int d=0,k=39;
	char a=0;
	scanf("%c",&a);
	d=a;
	for(int i=65;i<=d;i++)
	{
		if(i==65)
		{
			printf("%40c\n",i);
			k--;
		}
		else if(i<d)
		{
			for(int j=0;j<k;j++)
			{
				printf(" ");
			}
			k--;
			printf("%c",i);
			for(int j=0;j<(i-64)*2-3;j++)
			printf(" ");
			printf("%c",i);
			printf("\n");
		}
		else
		{
			for(int j=0;j<k;j++)
			{
				printf(" ");
			}
			k--;
			for(int j=0;j<(i-64)*2-1;j++)
			printf("%c",i);
		}
	}
}
/*
                                       A
                                      B B
                                     C   C
                                    D     D
                                   EEEEEEEEE
*/
