#include<stdio.h>
#include<string.h>
int main()
{
	int i=0;	
	char a[1000]="",b[1000]="";
	const char *p="\0";
	char *token;
	while(scanf("%s",&a)!=EOF)
	{
		for(i=0;i<1000;i++)
		{
			if(a[i]=='5')
			a[i]=' ';
		}
		token=strtok(a,p);
		while((p = strtok(NULL,p)))
		{
		printf("%s\n",token);
    	}
	}
	return 0;
}
