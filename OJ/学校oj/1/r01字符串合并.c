#include<stdio.h>
#include<string.h>
int main()
{
	char a[100]="",b[100]="",c[200]="";
	while(scanf("%s\n%s",&a,&b)!=EOF)
    {
	for(int i=0;i<strlen(a);i++)
	{
		c[i]=a[i];
	}
	for(int i=0;i<strlen(b);i++)
	{
		c[i+strlen(a)]=b[i];
	}
	printf("%s\n",c);
    }
  return 0;
}
