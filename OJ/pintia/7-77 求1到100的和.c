#include<stdio.h>

int main()
{
    int sum = 0;
    for(int i=1;i<101;i++)
    {
        sum+=i;
    }
    printf("sum = %d",sum);
    return 0;
}
