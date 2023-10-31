//P1150 Peter的烟
#include<stdio.h>
int main()
{
    long n,k,d=0,cnt=0;
    scanf("%ld %ld",&n,&k);
    while(n>0)
    {
        d++;
        cnt++;
        n--;
        if(d==k)
        {
            n++;
            d=0;
        }
    }
    printf("%ld",cnt);
}