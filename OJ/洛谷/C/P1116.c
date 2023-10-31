//P1116 车厢重组
#include<stdio.h>
int main()
{
    int n=0,cishu=0,a[10001]={0},z=0;
    scanf("%d",&n);
    for(int i=1;i<n+1;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<n+1;i++)
    {
       for(int j=1;j<n;j++)
       {
           if(a[j]>a[j+1])
           {
               cishu++;
               z=a[j];
               a[j]=a[j+1];
               a[j+1]=z;
           }
       }
    }
    printf("%d",cishu);
}