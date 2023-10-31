#include<stdio.h>
int main()
{
	unsigned long long x=0,s=1,n=1,g=1;
	
	scanf("%llu",&x);
	
	while(s<x)
	{
		s=s*10+1;
		n++;
	}
	int y;
    do{
        y=s%x;
        printf("%llu",s/x);
        if(y==0){
            break;
        }
        s=y*10+1;
        n++;
    }while(y!=0);
    printf(" %llu",n);
	return 0;
}
