#include <iostream>
#include <cstdio>

using namespace std;

int n, m, k, b[1005][1005] = {0};      // n是行数，m是列数，k是颜色的数量，b是用来存储输入的数字
int ans1[1005] = {0}, ans[1005] = {0}; // ans1是用来存储每一列的颜色数量，ans是用来存储每一行的颜色数量

int main()
{
    cin >> n >> m >> k;         // 输入
    for (int i = 0; i < n; i++) // 循环
    {
        for (int j = 0; j < m; j++) // 循环
        {
            cin >> b[i][j]; // 输入
        }
    }
    for (int i = 0; i < m; i++) // 循环
    {
        for (int j = 0; j < n; j++) // 循环
        {
            ans1[b[j][i]]++; // 计算
        }
        for (int z = 1; z <= k; z++) // 循环
        {
            if (ans1[z] > 0) // 如果大于0
            {
                ans[z]++;    // 答案加一
                ans1[z] = 0; // 赋值
            }
        }
    }

    for (int i = 1; i <= k; i++) // 循环
    {
        cout << ans[i] << " "; // 输出
    }
}