#include <stdio.h>

int main()
{
    long o = 0, x = 0, v = 0, maxv = 9999999, minv = 0; // o为普通金属,x为特殊金属,v为转换率,maxv为最大转换率,minv为最小转换率
    int n = 0, i = 0;                                   // n为输入的数,i为循环变量
    scanf("%d", &n);                                    // 输入n
    for (i = 0; i < n; i++)                             // 循环n次
    {

        scanf("%ld %ld", &o, &x);   // 输入o和x
        if (o / x < maxv)           // 如果o/x小于maxv
            maxv = o / x;           // maxv为o/x
        if (o / (x + 1) + 1 > minv) // 如果o/(x+1)+1大于minv
            minv = o / (x + 1) + 1; // minv为o/(x+1)+1
    }
    printf("%ld %ld", minv, maxv); // 输出minv和maxv
    return 0;
}