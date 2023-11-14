#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char s[10] = {0};           // 用来存储输入的字符串
    int ans = 0;                // 用来存储答案
    gets(s);                    // 输入
    int n = strlen(s);          // 计算长度
    for (int i = 0; i < n; i++) // 循环
    {
        if ('0' <= s[i] && s[i] <= '9') // 如果是数字
            ans++;                      // 答案加一
        if ('a' <= s[i] && s[i] <= 'z') // 如果是小写字母
            ans++;                      // 答案加一
        if ('A' <= s[i] && s[i] <= 'Z') // 如果是大写字母
            ans++;                      // 答案加一
    }
    cout << ans; // 输出
}