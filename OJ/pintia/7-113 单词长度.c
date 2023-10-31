#include<stdio.h>
int main()
{
	char a[1000]="";
	int c=0,l=0;
	for(int i=0;i<1000;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='.')
		break;
	}
	for(int i=0;i<1000;i++)
	{
		if(a[i]!=' '&&a[i]!='.')
		l++;
		if(a[i-1]!=' '&&(a[i]==' '||a[i]=='.'))
		{
			if(c!=0)
			printf(" ");
			if(l!=0)
			printf("%d",l);
			l=0;
			c++;
			if(a[0]==' '&&i==0)
			c--;
		}
		if(a[i]=='.')
		break;
	}
}
