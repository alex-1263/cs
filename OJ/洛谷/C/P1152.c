//P1152 欢乐的跳
#include<stdio.h>
int main()
{
    int n=0,flag=1,a[1000]={0};
    long long x=0,last=0,t=0;
    scanf("%d",&n);
    scanf(" %lld",&x);
    for(int i=1;i<n;i++)
    {
        last=x;
        scanf(" %lld",&x);
        if((last<0&&x<0)||(last>=0&&x>=0))
        {
            t=last-x;
        }
        else
        {
            if(last<0)
            last=-last;
            if(x<0)
            {
                t=last-x;
            }
            else
                t=last+x;
        }
        if(t<0)
        t=-t;
        if(t>=0&&t<=999)
        {
            a[t]++;
        }
    }
    for(int i=1;i<=n-1;i++)
    {
        if(a[i]!=1)
        flag=0;
    }
    if(flag==1)
    {
        printf("Jolly");
    }
    else
    {
        printf("Not jolly");
    }
}