#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

long long ans[30][30][30] = {0}; // 用来存储结果

long long w(long long a, long long b, long long c) // 递归函数
{

    if (a <= 0 || b <= 0 || c <= 0) // 如果有一个小于等于0
    {
        return 1; // 返回1
    }
    else if (a > 20 || b > 20 || c > 20) // 如果有一个大于20
    {
        return w(20, 20, 20); // 返回w(20,20,20)
    }
    else if (a < b && b < c) // 如果a<b<c
    {
        if (ans[a][b][c - 1] == 0) // 如果没有计算过
        {
            ans[a][b][c - 1] = w(a, b, c - 1); // 计算
        }
        if (ans[a][b - 1][c - 1] == 0) // 如果没有计算过
        {
            ans[a][b - 1][c - 1] = w(a, b - 1, c - 1); // 计算
        }
        if (ans[a][b - 1][c] == 0) // 如果没有计算过
        {
            ans[a][b - 1][c] = w(a, b - 1, c); // 计算
        }
        return ans[a][b][c - 1] + ans[a][b - 1][c - 1] - ans[a][b - 1][c]; // 返回结果
    }
    else // 如果不是a<b<c
    {
        if (ans[a - 1][b][c] == 0) // 如果没有计算过
        {
            ans[a - 1][b][c] = w(a - 1, b, c); // 计算
        }
        if (ans[a - 1][b - 1][c] == 0) // 如果没有计算过
        {
            ans[a - 1][b - 1][c] = w(a - 1, b - 1, c); // 计算
        }
        if (ans[a - 1][b][c - 1] == 0) // 如果没有计算过
        {
            ans[a - 1][b][c - 1] = w(a - 1, b, c - 1); // 计算
        }
        if (ans[a - 1][b - 1][c - 1] == 0) // 如果没有计算过
        {
            ans[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1); // 计算
        }
        return ans[a - 1][b][c] + ans[a - 1][b - 1][c] + ans[a - 1][b][c - 1] - ans[a - 1][b - 1][c - 1]; // 返回结果
    }
}

int main()
{
    long long a, b, c; // a,b,c是输入的数字
    while (1)          // 循环
    {
        cin >> a >> b >> c;                // 输入
        if (a == -1 && b == -1 && c == -1) // 如果输入的是-1 -1 -1
        {
            break; // 结束循环
        }
        printf("w(%lld, %lld, %lld) = ", a, b, c); // 输出
        cout << w(a, b, c) << endl;                // 输出
    }
}
// 总结代码思路:
//  1. 本题是一个递归题目，但是递归的次数很多，所以要用数组来存储结果，避免重复计算
//  2. 本题的递归思路是：
//     1. 如果有一个小于等于0，返回1
//     2. 如果有一个大于20，返回w(20,20,20)
//     3. 如果a<b<c，返回w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
//     4. 如果不是a<b<c，返回w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)
//  3. 本题的难点是：
//     1. 递归的次数很多，所以要用数组来存储结果，避免重复计算
//     2. 递归的思路要清晰，不要乱