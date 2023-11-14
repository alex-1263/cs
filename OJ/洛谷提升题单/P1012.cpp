#include <iostream>
#include <cstdio>

using namespace std;

int n = 0;                     // n<=20
string s[25] = {"a"}, t = "a"; // s[i]长度<=10
int main()
{
    cin >> n; // 输入n
    for (int i = 0; i < n; i++)
    { // 输入n个字符串
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    { // 排序
        for (int j = 0; j < n; j++)
        { // 冒泡排序
            if (s[i] >= s[j])
            {             // 如果s[i]大于s[j]，交换位置
                t = s[j]; // 交换位置
                s[j] = s[i];
                s[i] = t;
            }
            if (s[i] + s[j] >= s[j] + s[i])
            {             // 如果s[i]+s[j]大于s[j]+s[i]，交换位置
                t = s[j]; // 交换位置
                s[j] = s[i];
                s[i] = t;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i]; // 输出
    }
}
// 总结：字符串排序,按照字典序排序