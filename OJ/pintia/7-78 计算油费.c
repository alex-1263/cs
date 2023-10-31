#include<stdio.h>
int main()
{
    int z=0,l=0;
    double x=0;
    char f=0;
    scanf("%d %d %c",&l,&z,&f);
    if(z==90)
    {
        x=6.95*l;
    }
    if(z==93)
    {
        x=7.44*l;
    }
    if(z==97)
    {
        x=7.93*l;
    }
    if(f=='m')
    {
        x*=0.95;
    }
    if(f=='e')
    {
        x*=0.97;
    }
    printf("%.2lf",x);
    return 0;
}
