//P1059 [NOIP2006 普及组] 明明的随机数
#include<stdio.h>
int main()
{
    int a[1001]={0},x=0,n=0,ii=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(a[x]==0)
        {
            ii++;
            a[x]++;
        }
    }
    printf("%d\n",ii);
    for(int i=1;i<1001;i++)
    {
        if(a[i]!=0)
        printf("%d ",i);
    }
    return 0;
}