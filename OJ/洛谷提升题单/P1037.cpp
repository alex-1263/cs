#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int x, ans = 0, a[11] = {0}, i; // x为数，ans为答案，a为数组，i为循环变量
    cin >> x;                       // 输入x
    int flag = 0;                   // flag为标记
    if (x < 0)                      // 如果x小于0
    {
        x = -x;   // x等于-x
        flag = 1; // 标记为1
    }
    for (i = 1;; i++) // 遍历
    {
        a[i] = x % 10; // a[i]等于x%10
        x = x / 10;
        if (x <= 0)
            break;
    }
    for (int j = 1, k = i; j <= i; j++, k--)
    {
        ans += a[j] * pow(10, k - 1);
    }
    if (flag == 1)
        ans = -ans;

    cout << ans;
}