#include <iostream>
#include <cstdio>

using namespace std;

int main() // 主函数
{
    int a = 19, b, c;          // a是每个签字笔的价格，b是买了几个，c是剩下的钱
    cin >> b >> c;             // 输入买了几个和剩下的钱
    int sum = b * 10 + c, ans; // sum是总钱数，ans是答案
    ans = sum / a;             // 算出答案
    cout << ans;               // 输出答案
}