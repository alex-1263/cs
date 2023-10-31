//P1161 开灯
#include<stdio.h>
int main()
{
    char a[2000001]="\0";
	long x=0;
    int n=0,t=0,i,j;
    double A=0; 
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %d",&A,&t);
        for(j=1;j<=t;j++)
        {
            x=j*A;
            if(a[x]=='\0')
            a[x]++;
            else
            a[x]--;
        }
    }
    for(x=1;x<2000001;x++)
    {
        if(a[x]==1)
        {
            printf("%ld",x);
            break;
        }
    }
}