#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int panduan(int n, int x) // 判断n中有几个x
{
    int ans = 0, a;   // ans是答案，a是每一位的数字
    for (int i = 1;;) // 循环
    {
        a = n % 10; // 取出最后一位
        if (a == x) // 如果是x
            ans++;  // 答案加一
        n = n / 10; // 去掉最后一位
        if (n <= 0) // 如果n小于等于0
            break;  // 结束循环
    }
    return ans; // 返回答案
}

int main()
{
    int n = 0, ans = 0, x;       // n是输入的数字，ans是答案，x是要找的数字
    cin >> n >> x;               // 输入
    for (int i = 1; i <= n; i++) // 循环
    {
        ans += panduan(i, x); // 计算
    }
    cout << ans; // 输出
}