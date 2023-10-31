#include <stdio.h>
int main()
{
	int c,d;
	scanf("%d",&c);
	if(c>=90&&c<=100)
		d='A';
		else if(c>=80) d='B';
		else if(c>=70) d='C';
		else if(c>=60) d='D';
		else d='E';
	printf("%c",d);
	return 0;

} 
