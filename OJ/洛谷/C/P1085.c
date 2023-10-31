//P1085 [NOIP2004 普及组] 不高兴的津津
#include<stdio.h>
int main()
{
    int a=0,b=0,max=0,maxd=0;
    for(int i=0;i<7;i++)
    {
        scanf("%d %d",&a,&b);
        if(a+b>max&&a+b>8)
        {
            max=a+b;
            maxd=i+1;
        }
    }
    printf("%d",maxd);
}