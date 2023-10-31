//P1075 [NOIP2012 普及组] 质因数分解
#include<stdio.h>
int main()
{
    long long  x=0,i=0;
    scanf("%lld",&x);
    for(i=2;i<x;i++)
    {
        if(x%i==0)
        {
            printf("%lld",x/i);
            break;
        }
        
    }
}