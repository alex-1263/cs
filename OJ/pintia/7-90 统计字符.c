#include<stdio.h>
#include<string.h>
int main()
{
	char a[11]="";
	int s=0,y=0,k=0,q=0;
	for(int i=0;i<10;i++)
	scanf("%c",&a[i]);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		s++;
		else if(a[i]==' '||a[i]=='\n')
		k++;
		else if(a[i]>='a'&&a[i]<='z')
		y++;
		else if(a[i]>='A'&&a[i]<='Z')
		y++;
		else
		q++;
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d",y,k,s,q);
}

