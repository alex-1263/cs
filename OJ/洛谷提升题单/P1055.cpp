#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() // P1055 ISBN号码
{
    char s[14] = {0};                   // s为ISBN号码
    gets(s);                            // 输入ISBN号码
    int a[10] = {0}, ans = 0;           // a为数组，ans为答案
    for (int i = 0, k = 0; i < 13; i++) // 遍历
    {
        if (s[i] >= '0' && s[i] <= '9') // 如果s[i]是数字
        {
            a[k] = s[i] - 48; // a[k]等于s[i]-48
            k++;              // k加1
        }
    }
    if (s[12] == 'X') // 如果s[12]等于X
    {
        a[9] = 10; // a[9]等于10
    }
    for (int k = 0; k < 9; k++) // 遍历
    {
        ans += a[k] * (k + 1); // ans加上a[k]*(k+1)
        ans = ans % 11;        // ans对11取余
    }
    if (ans == a[9]) // 如果ans等于a[9]
    {
        cout << "Right"; // 输出Right
    }
    else // 如果ans不等于a[9]
    {
        if (ans == 10)   // 如果ans等于10
            s[12] = 'X'; // s[12]等于X
        else             // 如果ans不等于10
        {
            s[12] = char(ans + 48); // s[12]等于ans+48
        }
        cout << s; // 输出s
    }
}