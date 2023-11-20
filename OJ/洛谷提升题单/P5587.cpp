#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s1, s2, tmp, tmp1, tmp2; // s1是第一个人的输入，s2是第二个人的输入，tmp是临时变量，tmp1是临时变量1，tmp2是临时变量2
int t, ans = 0;                 // t是输入的数字，ans是答案

int main()
{
    while (1)
    {
        getline(cin, tmp); // 输入

        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] == '<') // 如果是<
            {
                if (i == 0) // 如果是第一个
                {
                    tmp = tmp.substr(1); // 截取
                    i--;                 // i减一
                }
                else if (i == 1) // 如果是第二个
                {
                    tmp = tmp.substr(2); // 截取
                    i -= 2;              // i减二
                }
                else // 如果是其他
                {
                    tmp = tmp.substr(0, i - 1) + tmp.substr(i + 1); // 截取
                    i -= 2;                                         // i减二
                }
            }
        }
        s1 = s1 + tmp + "\\"; // 拼接
        if (tmp == "EOF")     // 如果是EOF
            break;            // 结束循环
    }
    while (1)
    {
        getline(cin, tmp); // 输入

        for (int i = 0; i < tmp.size(); i++) // 循环
        {
            if (tmp[i] == '<') // 如果是<
            {
                if (i == 0) // 如果是第一个
                {
                    tmp = tmp.substr(1); // 截取
                    i--;                 // i减一
                }
                else if (i == 1) // 如果是第二个
                {
                    tmp = tmp.substr(2); // 截取
                    i -= 2;              // i减二
                }
                else // 如果是其他
                {
                    tmp = tmp.substr(0, i - 1) + tmp.substr(i + 1); // 截取
                    i -= 2;                                         // i减二
                }
            }
        }
        s2 = s2 + tmp + "\\"; // 拼接
        if (tmp == "EOF")     // 如果是EOF
            break;            // 结束循环
    }
    cin >> t; // 输入
    while (1) // 循环
    {
        for (int i = 0; i < s1.size(); i++) // 循环
        {
            if (s1[i] == '\\') // 如果是'\'
            {
                tmp1 = s1.substr(0, i); // 截取
                if (tmp1 == "EOF")      // 如果是EOF
                    break;              // 结束循环
                s1 = s1.substr(i + 1);  // 截取
                break;                  // 结束循环
            }
        }
        for (int i = 0; i < s2.size(); i++) // 循环
        {
            if (s2[i] == '\\') // 如果是"\"
            {
                tmp2 = s2.substr(0, i); // 截取
                if (tmp2 == "EOF")      // 如果是EOF
                    break;              // 结束循环
                s2 = s2.substr(i + 1);  // 截取
                break;                  // 结束循环
            }
        }
        if (tmp1 == "EOF") // 如果是EOF
            break;
        if (tmp2 == "EOF") // 如果是EOF
            break;
        for (int i = 0; i < min(tmp1.size(), tmp2.size()); i++) // 循环
        {
            if (tmp1[i] == tmp2[i]) // 如果相等
            {
                ans++; // 答案加一
            }
        }
    }
    float kmp = 0;                      // kmp是答案
    kmp = (ans * 1.0 / t * 1.0) * 60.0; // 计算
    cout << (int)(kmp + 0.5);           // 输出
    return 0;                           // 结束
}