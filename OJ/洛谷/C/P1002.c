//P1002 [NOIP2002 普及组] 过河卒
long lj(int x,int y)            //递归函数 算路径
{
    int sum=0;
    if(x!=0&&y!=0)
    return lj(x,y-1)+lj(x-1,y);
    if(x==0&&y!=0)
    return lj(x,y-1);
    if(y==0&&x!=0)
    return lj(x-1,y);
    if(x==0&&y==0)
    return 1;
}

#include<stdio.h>
int main()
{
    long long sum=0;
    struct qi
    {
        int x,y;
        long long fangfa;
    };
    struct qi ma,P[8]={0},end;
    scanf("%d %d %d %d",&end.x,&end.y,&ma.x,&ma.y);
    P[1].x=ma.x+2;
    P[2].x=ma.x+1;
    P[3].x=ma.x-1;
    P[4].x=ma.x-2;
    P[5].x=ma.x-2;
    P[6].x=ma.x-1;
    P[7].x=ma.x+1;
    P[8].x=ma.x+2;
    P[1].y=ma.y+1;
    P[2].y=ma.y+2;
    P[3].y=ma.y+2;
    P[4].y=ma.y+1;
    P[5].y=ma.y-1;
    P[6].y=ma.y-2;
    P[7].y=ma.y-2;
    P[8].y=ma.y-1;
    ma.fangfa=lj(ma.x,ma.y)*lj(end.x-ma.x,end.y-ma.y);
    for(int i=1;i<9;i++)
    {
        if(P[i].x>=0&&P[i].y>=0&&P[i].x<=end.x&&P[i].y<=end.y)
        {
            P[i].fangfa=lj(P[i].x,P[i].y)*lj(end.x-P[i].x,end.y-P[i].y);
        }
    }
    sum=lj(end.x,end.y)-ma.fangfa;
    for(int i=1;i<9;i++)
    {
        sum-=P[i].fangfa;
    }
    //判断点p5 4 ，6 7是否在棋盘里。
    //还要判断p8，p1是否也在棋盘里。
    printf("%lld",sum);
    return 0;
}