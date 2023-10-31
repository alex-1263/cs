//P1179 [NOIP2010 普及组] 数字统计
#include<stdio.h>
int main()
{
    int L=0,R=0,sum=0,a=0,b=0,c=0,d=0,e=0,f=0;
    scanf("%d %d",&L,&R);
    for(int i=L;i<=R;i++)
    {
        a=i/100000;
        b=(i%100000)/10000;
        c=(i%10000)/1000;
        d=(i%1000)/100;
        e=(i%100)/10;
        f=i%10;
        if(a==2)
        sum++;
        if(b==2)
        sum++;
        if(c==2)
        sum++;
        if(d==2)
        sum++;
        if(e==2)
        sum++;
        if(f==2)
        sum++;
    }
    printf("%d",sum);
}