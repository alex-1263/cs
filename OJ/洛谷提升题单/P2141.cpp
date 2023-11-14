#include <iostream>
#include <cstdio>

using namespace std;

long long a[105][105] = {0}; // 用来存储输入的数字

int main()
{
    int n, ans = 0;              // n是输入的数字，ans是答案
    cin >> n;                    // 输入
    for (int i = 1; i <= n; i++) // 循环
    {
        cin >> a[0][i];    // 输入
        a[i][0] = a[0][i]; // 赋值
    }
    for (int i = 1; i <= n; i++) // 循环
    {
        for (int j = 1; j < i; j++) // 循环
        {
            a[i][j] = a[0][j] + a[i][0]; // 计算
        }
    }
    for (int i = 1; i <= n; i++) // 循环
    {
        for (int j = 1; j <= i; j++) // 循环
        {
            for (int k = 1; k <= n; k++) // 循环
            {
                if (a[i][j] == a[k][0] && a[k][0] != 0) // 如果相等
                {
                    ans++;       // 答案加一
                    a[k][0] = 0; // 赋值
                }
            }
        }
    }
    cout << ans; // 输出
}