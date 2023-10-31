//P1200 [USACO1.1]你的飞碟在这儿Your Ride Is Here
#include<stdio.h>
int main()
{
    long A=1,B=1,aa,bb;
    char a[7]="",b[7]="";
    scanf("%s%s",&a,&b);
    for(int i=0;i<6;i++)
    {
        if(a[i]>=65&&a[i]<=90)
        {
            aa=a[i]-64;
            A*=aa;  
        }
       
    }
    for(int i=0;i<6;i++)
    {
        if(b[i]>=65&&b[i]<=90)
        {
            bb=b[i]-64;
            B*=bb;  
        }
       
    }
    if((A%47)==(B%47))
    {
        printf("GO");
    }
    else
    {
        printf("STAY");
    }
}