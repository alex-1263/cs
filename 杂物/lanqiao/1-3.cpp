#include <cstdio>

int main()
{
    long long a = 0, b = 0, w = 0, week = 0, last = 0, sum = 0, day = 0; // a,b分别为周内和周末的题数,w为一周做的题,week为周数,last为剩的题目,sum为输入的总题数,day为天数
    scanf("%lld %lld %lld", &a, &b, &sum);                               // 输入a,b,sum
    w = 5 * a + 2 * b;                                                   // 一周做的题
    week = sum / w;                                                      // 周数
    last = sum % w;                                                      // 剩的题目
    if (last == 0)                                                       // 如果剩的题目为0
    {
        day = week * 7; // 天数为周数*7
    }
    else if (last <= 5 * a) // 如果剩的题目小于等于5*a
    {
        day = week * 7 + last / a; // 天数为周数*7+剩的题目/周内题数
        if (last % a != 0)         // 如果剩的题目/周内题数有余数
            day++;                 // 天数+1
    }
    else if (last <= 5 * a + b) // 如果剩的题目小于等于5*a+b
    {
        day = week * 7 + 5 + 1; // 天数为周数*7+5+1
    }
    else
    {
        day = week * 7 + 5 + 2; // 天数为周数*7+5+2
    }
    printf("%lld", day); // 输出天数
    return 0;            // 返回0
}