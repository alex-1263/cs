#include<stdio.h>
int main()
{
    long A=1,B=1,aa,bb,i;
    char a[7]="",b[7]="";
    scanf("%s%s",&a,&b);
    for(i=0;i<6;i++)
    {
        if(a[i]=='\0')
        break;
        aa=a[i]-64;
        A*=aa;
    }
    for(i=0;i<6;i++)
    {
        if(a[i]=='\0')
        break;
        bb=b[i]-64;
        B*=bb;
    }
    printf("%ld %ld",A,B);
    if((A%47)==(B%47))
    {
        printf("GO");
    }
    else
    {
        printf("STAY");
    }
}
