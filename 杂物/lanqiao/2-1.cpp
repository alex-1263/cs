#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 平年每月天数
int num[100] = {5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 4, 7, 7, 5, 9, 5, 0, 3, 8, 7, 5, 8, 1, 5, 8, 6, 1, 8, 3, 0, 3, 7, 9, 2,
                7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3, 8, 5, 1, 6, 3, 4, 6, 7, 0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0,
                1, 0, 0, 9, 4, 8, 0, 9, 1, 2, 8, 5, 0, 2, 5, 3, 3}; // 100个数
int main()
{
    int i = 0, j = 0;        // 用于循环
    int ans = 0;             // 答案
    for (i = 1; i < 13; i++) // 遍历每个月
    {
        for (j = 1; j <= days[i]; j++) // 遍历每个月的每一天
        {
            string year = "2023"; // 年份
            string month;         // 月份
            string day;           // 日期
            if (i < 10)           // 如果月份小于10
            {
                month = "0" + to_string(i); // 月份为0+月份
            }
            else
            {
                month = to_string(i); // 月份为月份
            }
            if (j < 10)
            {
                day = "0" + to_string(j); // 日期为0+日期
            }
            else
            {
                day = to_string(j); // 日期为日期
            }
            string date = year + month + day;     // date为年份+月份+日期
            int k = 0;                            // 用于循环
            int flag = 0;                         // 用于计数
            for (k = 0; k < 100 && flag < 8; k++) // 遍历100个数
            {
                if (num[k] == date[flag] - '0') // 如果相等
                {
                    flag++; // 计数加一
                }
            }
            if (flag >= 8) // 如果计数大于等于8
                ans++;     // 答案加一
        }
    }
    printf("%d\n", ans); // 输出答案
    return 0;            // 返回0
}