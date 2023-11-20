#include <iostream>
#include <cstdio>

using namespace std;

long long fb[9706150] = {0}, k; // 用来存储斐波那契数列

int main()
{
    long long ans = 0;    // ans是答案
    cin >> k;             // 输入
    fb[1] = 0, fb[2] = 1; // 赋值
    for (int i = 3;; i++) // 循环
    {
        fb[i] = (fb[i - 1] + fb[i - 2]) % k; // 计算
        if (fb[i] == 1 && fb[i - 1] == 0)    // 如果满足条件
        {
            ans = i - 2; // 赋值
            break;       // 结束循环
        }
    }
    cout << ans; // 输出
}