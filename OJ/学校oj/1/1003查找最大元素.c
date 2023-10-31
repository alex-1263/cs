#include<stdio.h>
char a[101]="";
char max ;
int main()
{
	while(scanf("%s",a)!=EOF)
	{
		max=a[0];
		for(int i=0;i<100;i++)
		{
			if(a[i]=='\0')
			break;
			if(a[i]>max)
			max=a[i];
		}
		for(int i=0;i<100;i++)
		{
			if(a[i]=='\0')
			break;
			printf("%c",a[i]);
			if(a[i]==max)
			printf("(max)");
		}
		printf("\n");
	}
	return 0;
}
