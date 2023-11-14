#include <iostream>
#include <cstdio>

using namespace std;

long long dp[100005] = {0}, k; // dp为动态规划数组，k为最大步数

int main() // 主函数
{
    long long x;                       // x为台阶数
    cin >> x >> k;                     // 输入x和k
    dp[1] = 1;                         // dp[1]等于1
    dp[2] = 2;                         // dp[2]等于2
    for (long long i = 2; i <= k; i++) // 遍历
    {
        dp[i] = (dp[i - 1] * 2) % 100003; // dp[i]等于dp[i-1]*2对100003取余
    }
    for (long long i = k + 1; i <= x; i++) // 遍历
    {
        long long y = 0;                   // y等于0
        for (long long j = 1; j <= k; j++) // 遍历
        {
            y += dp[i - j]; // y加上dp[i-j]
        }
        dp[i] = y % 100003; // dp[i]等于y对100003取余
    }
    cout << dp[x]; // 输出dp[x]
}