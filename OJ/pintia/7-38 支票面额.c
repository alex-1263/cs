#include<stdio.h>
int main()
{
	int y=0,f=0,n=0,flag=0;
	scanf("%d",&n);
	for(y=0;y<100;y++)
	{
		
		for(f=1;f<100;f++)
		{
				if(2*f+n<100)
			{
				if(2*y==f&&2*f+n==y)
				{
					printf("%d.%d\n",y,f);
					flag=1;
					break;
				}
			}	
				if(2*f+n>=100)
			{
				if(2*y+1==f&&2*f+n-100==y)
				{
					printf("%d.%d\n",y,f);
					flag=1;
					break;
				}
			}
				if(2*f+n>=200)
			{
				if(2*y+2==f&&2*f+n-200==y)
				{
					printf("%d.%d\n",y,f);
					flag=1;
					break;
				}
			}
		}
	}
	if(flag==0)
	{
		printf("No Solution\n");
	}
	return 0;
}
/*
	2y元2f分+n分=f元y分
	所以原本有n+2f元+2y分 
*/
