//P1089 [NOIP2004 提高组] 津津的储蓄计划
#include<stdio.h>
int main()
{
    int q=0,c=0,kaizhi=0,flag=0;
    for(int i=1;i<13;i++)
    {
        q+=300;
        scanf("%d",&kaizhi);
        q-=kaizhi;
        if(q<0&&flag==0)
        flag=i;
        c+=q/100;
        q%=100;
    }
    if(flag==0)
    printf("%d",c*120+q);
    else
    printf("-%d",flag);
}