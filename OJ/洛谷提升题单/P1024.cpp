#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

float a = 0, b = 0, c = 0, d = 0; // a,b,c,d分别代表四个系数
int sum = 0;                      // sum代表有多少个解
float ans[3] = {0};               // ans数组用来存储解

float f(float x) // f(x)函数
{
    float ans = a * x * x * x + b * x * x + c * x + d; // ans代表f(x)的值
    ans = round(ans * 100) / 100;                      // 四舍五入
    if (ans == -0)                                     // 如果ans等于-0，ans等于0
    {
        ans = 0;
    }

    return ans; // 返回ans
}

int panduan(float x1, float x2) // 判断是否符合条件
{
    if ((f(x1) > 0 && f(x2) < 0) || (f(x1) < 0 && f(x2) > 0)) // 如果f(x1)和f(x2)异号
    {
        return 1; // 返回1
    }
    else
    {
        return 0; // 返回0
    }
}

void er(float x1, float x2) // 二分法
{
    if (panduan(x1, x2)) // 如果符合条件
    {
        float xa = round(x1 * 100) / 100; // 四舍五入
        float xc = round(x2 * 100) / 100; // 四舍五入
        float xb = (xa + xc) / 2;         // xb为xa和xc的中点
        xb = round(xb * 100) / 100;       // 四舍五入
        if (f(xb) == 0)                   // 如果f(xb)等于0
        {
            ans[sum] = xb; // 把xb存入ans数组
            sum++;         // sum加1
        }
        else if (f(xa) == 0) // 如果f(xa)等于0
        {
            ans[sum] = xa; // 把xa存入ans数组
            sum++;         // sum加1
        }
        else if (f(xc) == 0) // 如果f(xc)等于0
        {
            ans[sum] = xc; // 把xc存入ans数组
            sum++;         // sum加1
        }
        else // 如果f(xb)不等于0
        {
            er(xa, xb); // 递归
            er(xb, xc); // 递归
        }
    }
    else if (x2 - x1 >= 1) // 如果x2-x1大于等于1
    {
        float xa = round(x1 * 100) / 100; // 四舍五入
        float xc = round(x2 * 100) / 100; // 四舍五入
        float xb = (xa + xc) / 2;         // xb为xa和xc的中点
        er(xa, xb);                       // 递归
        er(xb, xc);                       // 递归
    }
}

int main()
{
    cin >> a >> b >> c >> d;    // 输入a,b,c,d
    er(-100, 100);              // 二分法
    sort(ans, ans + 3);         // 排序
    for (int i = 0; i < 3; i++) // 输出
    {
        if (i != 0) // 如果不是第一个数
        {
            cout << " "; // 输出空格
        }
        printf("%.2f", ans[i]); // 输出ans[i]
    }
}
// 总结：二分法，四舍五入，排序,再具体一些，
// 二分法的思想是，如果f(x1)和f(x2)异号，那么f(x)在x1和x2之间一定有一个解，所以可以用二分法来求解
// 如果f(x1)和f(x2)同号，那么f(x)在x1和x2之间一定没有解，所以不用求解
// 四舍五入的方法是，先把数乘以100，然后四舍五入，再除以100，这样就可以保留两位小数。排序的方法是，先把ans数组排序，然后输出。