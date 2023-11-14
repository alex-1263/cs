#include <iostream>
#include <cstdio>

using namespace std;

int sum[1005] = {0}; // sum为答案

int main()
{
    sum[0] = 0; // 初始化
    sum[1] = 1; // 初始化
    sum[2] = 2;
    sum[3] = 2;
    sum[4] = 4;
    int x = 0; // x为数
    cin >> x;  // 输入x
    if (x > 4) // 如果x大于4
    {
        for (int i = 5; i <= x; i++) // 遍历
        {
            if (i % 2 == 0) // 如果i是偶数
            {
                sum[i] = sum[i - 1] + sum[i / 2]; // sum[i]等于sum[i-1]+sum[i/2]
            }
            else // 如果i是奇数
            {
                sum[i] = sum[i - 1]; // sum[i]等于sum[i-1]
            }
        }
    }
    cout << sum[x]; // 输出答案
    return 0;
}
// 总结：动态规划，sum[i]等于sum[i-1]+sum[i/2]，如果i是偶数，sum[i]等于sum[i-1]，如果i是奇数