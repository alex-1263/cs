#include <iostream>
#include <cstdio>

using namespace std;

int ansa = 0, ansb = 0, a[205] = {0}, b[205] = {0}; // 0石头 1剪刀 2布 3蜥蜴 4斯波克

void caiquan(int x, int y) // 0石头 1剪刀 2布 3蜥蜴 4斯波克
{
    if (x != y) // 不相等
    {
        if (x == 0) // 石头
        {
            if (y == 1 || y == 4) // 剪刀 斯波克
            {
                ansa++;
            }
            else
            {
                ansb++;
            }
        }
        else if (x == 1) // 剪刀
        {
            if (y == 0 || y == 3) // 石头 蜥蜴
            {
                ansb++;
            }
            else
            {
                ansa++;
            }
        }
        else if (x == 2) // 布
        {
            if (y == 1 || y == 4) // 剪刀 斯波克
            {
                ansa++;
            }
            else
            {
                ansb++;
            }
        }
        else if (x == 3) // 蜥蜴
        {
            if (y == 0 || y == 1) // 石头 剪刀
            {
                ansb++;
            }
            else
            {
                ansa++;
            }
        }
        else if (x == 4) // 斯波克
        {
            if (y == 0 || y == 1) // 石头 剪刀
            {
                ansa++;
            }
            else
            {
                ansb++;
            }
        }
    }
}

int main()
{
    int n = 0, na = 0, nb = 0;   // n次 na个人 nb个人
    cin >> n >> na >> nb;        // 输入
    for (int i = 0; i < na; i++) // 输入
    {
        cin >> a[i]; // 输入
    }
    for (int i = 0; i < nb; i++) // 输入
    {
        cin >> b[i]; // 输入
    }
    for (int i = 0; i < n; i++) // 比较
    {
        caiquan(a[i % na], b[i % nb]); // 比较
    }
    cout << ansa << " " << ansb; // 输出
}