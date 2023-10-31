#include<stdio.h>
int main()
{
	char a[81]={ };
	int x=0,d=0;
	for(int i=0;i<81;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n')
		break;
	}
	for(int i=0;i<81;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			d++;
			if(a[i]=='A')
			x++;
			if(a[i]=='E')
			x++;
			if(a[i]=='I')
			x++;
			if(a[i]=='O')
			x++;
			if(a[i]=='U')
			x++;
		}
	}
	printf("%d",d-x);
	return 0;
}
