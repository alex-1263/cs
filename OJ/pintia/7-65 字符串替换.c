#include<stdio.h>
int main()
{
	char a[81]={ },z='A',x='Z';
	int d=0;
	for(int i=0;i<81;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n')
		break;
	}
	for(int i=0;i<81;i++)
	{
		if(a[i]<='Z'&&a[i]>='A')
		{
			a[i]=155-a[i];
		}
		printf("%c",a[i]);
	}
	return 0;
}
