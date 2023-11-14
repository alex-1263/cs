#include <iostream>
#include <cstdio>

using namespace std;

int dg(int x) // 递归函数
{
    int ans = 0; // ans为答案
    if (x == 1)  // 如果x等于1
    {
        ans = 1;    // 答案等于1
        return ans; // 返回答案
    }
    for (int i = (x / 2); i >= 1; i--) // 遍历
    // 从x/2开始遍历，因为x/2是x的最大因数
    {
        ans += dg(i); // 递归
    }
    if (x != 1) // 如果x不等于1
    {
        ans++; // 答案加1
    }
    return ans; // 返回答案
}

int main()
{
    int x = 0;     // x为数
    cin >> x;      // 输入x
    cout << dg(x); // 输出答案
    return 0;
}