#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int ans = 0; // ans为答案

void dfs(int x, int d, int y) // dfs
{
    if (d == 1 && x >= y) // 如果d等于1，且x大于等于y
    {
        ans++; // 答案加1
    }
    else // 如果d不等于1，或者x不大于等于y
    {
        for (int i = y; i <= x - (d - 1); i++) // 遍历
        {
            if (x >= y) // 如果x大于等于y
            {
                dfs(x - i, d - 1, i); // 递归
            }
        }
    }
}

int main()
{
    int a, b;      // a,b分别代表两个数
    cin >> a >> b; // 输入a,b
    dfs(a, b, 1);  // dfs
    cout << ans;   // 输出答案
}
