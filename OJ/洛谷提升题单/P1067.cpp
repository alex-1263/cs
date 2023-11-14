#include <iostream>
#include <cstdio>

using namespace std;

int a[105] = {0}; // a为系数

int main() // 主函数
{
    int n = 0;                      // n为数
    cin >> n;                       // 输入n
    for (int i = 0; i < n + 1; i++) // 遍历
    {
        cin >> a[i]; // 输入系数
    }
    for (int i = 0, j = n; i < n + 1; i++, j--) // 遍历
    {
        if (a[i] != 0) // 如果系数不等于0
        {
            if (j == n) // 如果是最高次幂
            {
                if (j == 0) // 如果是常数项
                {
                    cout << a[i]; // 输出系数
                }
                else // 如果不是常数项
                {
                    if (a[i] == 1) // 如果系数为1
                    {
                        cout << "x^" << j; // 输出x^j
                    }
                    else if (a[i] == -1) // 如果系数为-1
                    {
                        cout << "-x^" << j; // 输出-x^j
                    }
                    else // 如果系数不为1或-1
                    {
                        cout << a[i] << "x^" << j; // 输出a[i]x^j
                    }
                }
            }
            else if (j == 1) // 如果是次高次幂
            {
                if (a[i] > 0) // 如果系数大于0
                {
                    if (a[i] == 1) // 如果系数为1
                    {
                        cout << "+x"; // 输出+x
                    }
                    else // 如果系数不为1
                    {
                        cout << "+" << a[i] << "x"; // 输出+ax
                    }
                }
                else // 如果系数小于0
                {
                    if (a[i] == -1) // 如果系数为-1
                    {
                        cout << "-x"; // 输出-x
                    }
                    else // 如果系数不为-1
                    {
                        cout << a[i] << "x"; // 输出ax
                    }
                }
            }
            else if (j == 0) // 如果是常数项
            {
                if (a[i] > 0) // 如果系数大于0
                {
                    cout << "+" << a[i]; // 输出+系数
                }
                else // 如果系数小于0
                {
                    cout << a[i]; // 输出系数
                }
            }
            else // 如果是其他次幂
            {
                if (a[i] > 0) // 如果系数大于0
                {
                    if (a[i] == 1) // 如果系数为1
                    {
                        cout << "+"
                             << "x^" << j; // 输出+x^j
                    }
                    else // 如果系数不为1
                    {
                        cout << "+" << a[i] << "x^" << j; // 输出+ax^j
                    }
                }
                else // 如果系数小于0
                {
                    if (a[i] == -1) // 如果系数为-1
                    {
                        cout << "-x^" << j; // 输出-x^j
                    }
                    else // 如果系数不为-1
                    {
                        cout << a[i] << "x^" << j; // 输出ax^j
                    }
                }
            }
        }
    }

    return 0;
}