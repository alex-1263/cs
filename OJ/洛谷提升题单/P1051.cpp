#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int n = 0, pjf, bjf, lw, sum = 0, max = 0, ans = 0; // n为人数，pjf为平均分，bjf为班级评分，lw为论文数，sum为总奖金，max为最大奖金，ans为当前奖金
    char flag1, flag2;                                  // flag1为是否是西部省份，flag2为是否是班干部
    string name, maxname;                               // name为姓名，maxname为最大奖金的人的姓名
    cin >> n;                                           // 输入n
    for (int i = 0; i < n; i++)                         // 遍历
    {
        cin >> name >> pjf >> bjf >> flag1 >> flag2 >> lw; // 输入
        ans = 0;                                           // 初始化
        if (pjf > 80 && lw >= 1)                           // 如果pjf大于80，且lw大于等于1
            ans += 8000;                                   // ans加8000
        if (pjf > 85 && bjf > 80)                          // 如果pjf大于85，且bjf大于80
            ans += 4000;                                   // ans加4000
        if (pjf > 90)                                      // 如果pjf大于90
            ans += 2000;                                   // ans加2000
        if (pjf > 85 && flag2 == 'Y')                      // 如果pjf大于85，且flag2为Y
            ans += 1000;                                   // ans加1000
        if (bjf > 80 && flag1 == 'Y')                      // 如果bjf大于80，且flag1为Y
            ans += 850;                                    // ans加850
        if (ans > max)                                     // 如果ans大于max
        {
            max = ans;      // max等于ans
            maxname = name; // maxname等于name
        }
        sum += ans; // sum加ans
    }
    cout << maxname << endl // 输出
         << max << endl     // 输出
         << sum;            // 输出
}