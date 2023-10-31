//P1035 [NOIP2002 普及组] 级数求和
#include<stdio.h>
int main()
{
    long k=0,i=0;
    double sum=0;
    scanf("%d",&k);
    for(i=1;sum<=k;i++)
    {
        sum+=1.0/i;
    }
    i--;
    printf("%ld",i);
    return 0;
}