#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long a, b, c, n, d, ans;      // a是第一项，b是第二项，c是第三项，n是项数，d是公差，ans是答案
    cin >> a >> b >> n;                // 输入
    d = b - a;                         // 计算公差
    ans = n * a + n * (n - 1) * d / 2; // 计算答案
    cout << ans;                       // 输出
}