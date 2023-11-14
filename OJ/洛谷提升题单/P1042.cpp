#include <iostream>
#include <cstdio>

using namespace std;

char s[2505][30] = {0}; // s为比赛记录

int main()
{
    int flag = 0, a = 0, b = 0;    // flag为标记，a为甲的得分，b为乙的得分
    for (int i = 0; i < 2505; i++) // 输入
    {
        for (int j = 0; j < 25; j++) // 输入
        {
            cin >> s[i][j];     // 输入
            if (s[i][j] == 'E') // 如果输入E
            {
                flag = 1; // 标记为1
                break;    // 跳出循环
            }
        }
        if (flag)  // 如果标记为1
            break; // 跳出循环
    }
    flag = 0;                      // 标记为0
    for (int i = 0; i < 2505; i++) // 遍历
    {
        for (int j = 0; j < 25; j++) // 遍历
        {
            if (s[i][j] == 'E') // 如果输入E
            {
                flag = 1; // 标记为1
                break;    // 跳出循环
            }
            else if (s[i][j] == 'W') // 如果输入W
            {
                a++; // 甲得分加1
            }
            else if (s[i][j] == 'L') // 如果输入L
            {
                b++; // 乙得分加1
            }
            if ((a >= 11 || b >= 11) && ((a - b >= 2) || (b - a >= 2))) // 如果甲或乙的得分大于等于11，并且甲或乙的得分减去另一个的得分大于等于2
            {
                cout << a << ":" << b << endl; // 输出
                a = 0, b = 0;                  // 甲乙得分清零
            }
        }
        if (flag) // 如果标记为1
        {
            cout << a << ":" << b << endl; // 输出
            break;
        }
    }
    a = 0, b = 0;                  // 甲乙得分清零
    cout << endl;                  // 输出空行
    flag = 0;                      // 标记为0
    for (int i = 0; i < 2505; i++) // 遍历
    {
        for (int j = 0; j < 25; j++) // 遍历
        {
            if (s[i][j] == 'E') // 如果输入E
            {
                flag = 1;
                break;
            }
            else if (s[i][j] == 'W') // 如果输入W
            {
                a++; // 甲得分加1
            }
            else if (s[i][j] == 'L') // 如果输入L
            {
                b++; // 乙得分加1
            }
            if ((a >= 21 || b >= 21) && ((a - b >= 2) || (b - a >= 2))) // 如果甲或乙的得分大于等于21，并且甲或乙的得分减去另一个的得分大于等于2
            {
                cout << a << ":" << b << endl; // 输出
                a = 0, b = 0;                  // 甲乙得分清零
            }
        }
        if (flag) // 如果标记为1
        {
            cout << a << ":" << b << endl; // 输出
            break;                         // 跳出循环
        }
    }
}
// 总结：模拟，遍历，判断，输出
