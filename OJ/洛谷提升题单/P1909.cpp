#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n = 0, ans, a1, a2, c1, c2, b1, b2, p1, p2, p3; // n是输入的数字，ans是答案，a1是a的价格，a2是a的数量，c1是c的价格，c2是c的数量，b1是b的价格，b2是b的数量，p1是a的总价，p2是b的总价，p3是c的总价
    cin >> n >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;       // 输入
    p1 = n / a1;                                        // 计算a的总价
    if (n % a1 != 0)                                    // 如果不能整除
        p1++;                                           // 加1
    p1 = p1 * a2;                                       // 计算a的总价
    p2 = n / b1;                                        // 计算b的总价
    if (n % b1 != 0)                                    // 如果不能整除
        p2++;                                           // 加1
    p2 = p2 * b2;                                       // 计算b的总价
    p3 = n / c1;                                        // 计算c的总价
    if (n % c1 != 0)                                    // 如果不能整除
        p3++;                                           // 加1
    p3 = p3 * c2;                                       // 计算c的总价
    ans = min(p1, min(p2, p3));                         // 比较
    cout << ans;                                        // 输出
}