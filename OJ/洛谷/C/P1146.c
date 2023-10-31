//P1146 硬币翻转
#include<stdio.h>
int main()
{
    int a[100]={0},n;
    scanf("%d",&n);
    printf("%d",n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j!=i)
            {
                if(a[j]==0)
                a[j]++;
                else
                a[j]--;
            }
        }
        printf("\n");
        for(int j=0;j<n;j++)
        printf("%d",a[j]);
    }
}