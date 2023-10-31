#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[10];
	long x=0;
	int q=0;
	while(scanf("%s",&a)!=EOF)
	{
		x=0;
		for(int i=0;;i++)
		{
			if(i!=strlen(a)-1)
			{
				if(a[i]>='0'&&a[i]<='9')
				{
					q=a[i]-48;
					x=(x+q)*16;
				}
				if(a[i]>='A'&&a[i]<='F')
				{
					q=a[i]-55;
					x=(x+q)*16;
				}
			}
			else
			{
				if(a[i]>='0'&&a[i]<='9')
				{
					q=a[i]-48;
					x=x+q;
				}
				if(a[i]>='A'&&a[i]<='F')
				{
					q=a[i]-55;
					x=x+q;
				}
			}
			if(a[i]=='\0')
			break;
		}
		printf("%ld\n",x);
	}
}
