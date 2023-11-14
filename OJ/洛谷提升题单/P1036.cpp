#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n = 0, k = 0, x[22] = {0}, map[22] = {0}; // n为数的个数，k为数的个数，x为数，map为标记
int ans = 0;                                  // ans为答案

void panduan(int x) // 判断是否为素数
{
    int flag = 1;                      // flag为标记
    for (int i = 2; i <= sqrt(x); i++) // 遍历
    {
        if (x % i == 0) // 如果x能被i整除
        {
            flag = 0; // 标记为0
            break;    // 跳出循环
        }
    }
    if (flag == 1) // 如果标记为1
    {
        ans++; // 答案加1
    }
}

void dfs(int d, int sum, int y) // dfs
{
    if (d == k) // 如果d等于k
    {
        panduan(sum); // 判断是否为素数
    }
    for (int i = 1; i <= n; i++) // 遍历
    {
        if (map[i] == 0 && i > y) // 如果没有被标记，且大于y
        {
            map[i] = 1;                // 标记为1
            dfs(d + 1, sum + x[i], i); // 递归
            map[i] = 0;                // 标记为0
        }
    }
}

int main()
{
    cin >> n >> k;               // 输入n,k
    for (int i = 1; i <= n; i++) // 遍历
    {
        cin >> x[i]; // 输入数
    }
    dfs(0, 0, 0); // dfs
    cout << ans;  // 输出答案
}