//P1014 [NOIP1999 普及组] Cantor 表
#include<stdio.h>
int main()
{
    int n=0,sum=0,i1,i2,j=1;
    scanf("%d",&n);
    for(i1=0;sum<n;i1++)
    {
        sum+=i1;
    }
    if(sum==n)
    {
        i1--;
        if(i1%2==0)
        {
            printf("%d/1",i1);
        }
        else
        {
            printf("1/%d",i1);
        }
    }
    else
    {
        i1--;
        sum-=i1;
        i2=i1;
        n-=sum;
        while(n!=1)
        {
            i2--;
            j++;
            n--;
        }
        if(i1%2==0)
        {
            printf("%d/%d",j,i2);
        }
        else
        {
            printf("%d/%d",i2,j);
        }
    }
    return 0;
}