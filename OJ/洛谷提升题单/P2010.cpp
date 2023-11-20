#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s1[9] = {0}, s2[9] = {0};                                     // 用来存储输入的日期
int ss1[8] = {0}, ss2[8] = {0};                                    // 用来存储输入的日期
int ans = 0;                                                       // 用来存储答案
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 用来存储每个月的天数

void panduan(int s[]) // 判断是否是回文
{
    int flag = 1;                            // flag是标记
    for (int i = 3, k = 4; i >= 0; i--, k++) // 循环
    {
        if (s[i] != s[k]) // 如果不相等
        {
            flag = 0; // 标记为0
            break;    // 结束循环
        }
    }
    ans += flag; // 答案加上flag
}

int main()
{
    gets(s1);                      // 输入
    gets(s2);                      // 输入
    int dayy, month, year, flag11; // dayy是天数，month是月份，year是年份，flag11是标记
    for (int i = 0; i < 8; i++)    // 循环
    {
        ss1[i] = s1[i] - '0'; // 转换成数字
        ss2[i] = s2[i] - '0'; // 转换成数字
    }
    while (1) // 循环
    {
        flag11 = 1;                                                 // 标记为1
        month = ss1[4] * 10 + ss1[5];                               // 计算月份
        year = ss1[0] * 1000 + ss1[1] * 100 + ss1[2] * 10 + ss1[3]; // 计算年份
        dayy = ss1[6] * 10 + ss1[7];                                // 计算天数
        if (year % 4 == 0 && year % 100 != 0)                       // 如果是闰年
        {
            day[2] = 29; // 二月有29天
        }
        else if (year % 400 == 0) // 如果是闰年
        {
            day[2] = 29; // 二月有29天
        }
        else // 如果不是闰年
        {
            day[2] = 28; // 二月有28天
        }
        panduan(ss1);               // 判断是否是回文
        for (int i = 0; i < 8; i++) // 循环
        {
            if (ss1[i] != ss2[i]) // 如果不相等
                flag11 = 0;       // 标记为0
        }
        if (flag11)             // 如果是回文
            break;              // 结束循环
        if (dayy == day[month]) // 如果是月底
        {
            if (month == 12) // 如果是年底
            {
                year++;                     // 年份加一
                ss1[0] = year / 1000;       // 计算年份
                ss1[1] = (year / 100) % 10; // 计算年份
                ss1[2] = (year / 10) % 10;  // 计算年份
                ss1[3] = year % 10;         // 计算年份
            }
            dayy = 0;       // 天数归零
            month++;        // 月份加一
            if (month > 12) // 如果月份大于12
                month = 1;  // 月份归一
        }
        dayy++;              // 天数加一
        ss1[4] = month / 10; // 计算月份
        ss1[5] = month % 10; // 计算月份
        ss1[6] = dayy / 10;  // 计算天数
        ss1[7] = dayy % 10;  // 计算天数
    }
    cout << ans; // 输出
}