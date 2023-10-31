//P1425 小鱼的游泳时间
#include<stdio.h>
int main()
{
    int a,b,c,d,e,f;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    e=c-a;
    f=d-b;
    if(f<0)
    {
        f+=60;
        e--;
    }
    printf("%d %d",e,f);
}