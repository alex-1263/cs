#include<stdio.h>
#include<string.h>
int main()
{
	int s1[10]={0},s2[10]={0},d=0,flag=0,len;
	char a[21]="";
	char b[21]="";
	scanf("%s",&a);
	len=strlen(a);
	for(int i=0;i<len;i++)
	{
		d=a[i]-48;
		s1[d]++;
		d*=2;
		if(d<10)
		{
			d+=48;
			b[i]=d;
		}
		else
		{
			b[i-1]++;
			b[i]=d+38;
		}
	}
	if(a[0]>='5'&&a[0]<='9')
	{
		for(int j=len;j>-1;j--)
		{
			b[j+1]=b[j];
		}
		b[0]='1';
	}
	for(int i=0;i<len;i++)
	{
		d=b[i]-48;
		s2[d]++;
	}
	for(int i=0;i<10;i++)
	{
		if(s1[i]!=s2[i])
		{
			flag=-1;
			break;
		}
	}
	if(flag==0)
	printf("Yes\n");
	else
	printf("No\n");
	printf("%s",b);
}
