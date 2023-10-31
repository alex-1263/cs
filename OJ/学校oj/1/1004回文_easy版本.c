#include <stdio.h>
#include <string.h>
char a[100]="";
int key=0;
int main()
{
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		key =0;
		scanf("%s",&a);
		if(strlen(a)%2==0)
		{
			for(int j=0;j<strlen(a)/2;j++)
			{
				if(a[j]!=a[strlen(a)-1-j])
				{
					printf("no\n");
					key++;
					break;	
				}	
			}	
		}
		else
		{
			for(int j=0;j<(strlen(a)-1)/2;j++)
			{
				if(a[j]!=a[strlen(a)-1-j])
				{
					printf("no\n");
					key++;
					break;	
				}	
			}	
		}
		if(key==0)
		printf("yes\n");
	}
	return 0;	
} 
