#include<stdio.h>
#include<string.h>
int main()
{
	char a[100]="";
	int sum=0;
	gets(a);
	for(int i=strlen(a)-1;i>-1;i--)
	{
		sum+=a[i]-48;
	}
	printf("%d",sum);
}
