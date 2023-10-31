//P5705 【深基2.例7】数字反转
#include<stdio.h>
int main()
{
    char a[5];
    for(int i=0;i<5;i++)
    {
        scanf("%c",&a[i]);
    }
    for(int i=0,j=4;i<5;i++,j--)
    {
        printf("%c",a[j]);
    }
    return 0;
}