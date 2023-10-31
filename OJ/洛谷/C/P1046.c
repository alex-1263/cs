//P1046 [NOIP2005 普及组] 陶陶摘苹果
#include<stdio.h>
int main()
{
    int a[10]={0},h=0,n=0;
    for (int  i = 0; i <10; i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&h);
    for(int i=0;i<10;i++)
    {
        if(a[i]<=h+30)
        n++;
    }
    printf("%d",n);
}