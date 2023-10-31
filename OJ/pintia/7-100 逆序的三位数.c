#include<stdio.h>
int main()
{
	char a[4]="",b[4]="";
	int i=0,j=0;
	gets(a);
	for(i=2,j=0;i>-1;i--)
	{
		b[j]=a[i];
		j++;
		if(a[2]=='0'&&a[1]=='0') 
		{
			b[0]=a[0];
			break;
		}
		if(a[2]=='0')
		{
			b[0]=a[1];
			b[1]=a[0];
			break;
		}
	}
	printf("%s",b);
}
