//P1151 子数整数
#include<stdio.h>
int main()
{
    int k=0,i,w[6]={0},a1,a3,a2,cot=0;
    scanf("%d",&k);
    for(i=10000;i<=30000;i++)
    {
        w[2]=i%10000;
        w[3]=i%1000;
        w[4]=i%100;
        w[5]=i%10;
        w[1]=i/10000;
        w[2]/=1000;
        w[3]/=100;
        w[4]/=10;
        a1=w[1]*100+w[2]*10+w[3];
        a2=w[2]*100+w[3]*10+w[4];
        a3=w[3]*100+w[4]*10+w[5];
        if(a1%k==0&&a2%k==0&&a3%k==0)
        {
            cot++;
            printf("%d\n",i);
        }
    }
    if(cot==0)
    printf("No");
}