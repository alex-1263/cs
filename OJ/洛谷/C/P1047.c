//P1047 [NOIP2005 普及组] 校门外的树
#include<stdio.h>
int main()
{
    int a[10001]={0},m[100][2]={0},l=0,n=0,sum=0,i,j,k;
    scanf("%d %d",&l,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&m[i][0],&m[i][1]);
        for(j=m[i][0],k=0;k<=m[i][1]-m[i][0];j++,k++)
        {
            a[j]++;
        }
    }
    for(i=0;i<=l+1;i++)
    {
        if(a[i]>0)
        {
            sum++;
        }
    }
    printf("%d",l-sum+1);
}