#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000]="";
	int c=0,i=0;
	while(gets(a))
	{
		c=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]!=' '&&a[i+1]==' ')
			c++;
			if(a[i]!=' '&&a[i+1]=='\0')
			c++;
			if(a[i]=='#')
			break;
		}
		if(a[i]!='#')
		printf("%d\n",c);
		if(a[i]=='#')
		break;
	}
}
