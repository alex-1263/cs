#include<stdio.h>
int main()
{
	int v=0;
	scanf("%d",&v);
	if(v>60&&v<=500)
	{
	printf("Speed: %d - Speeding",v);
	}
	else 
	{
		printf("Speed: %d - OK",v);
	}
	return 0;
} 
