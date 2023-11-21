#include <stdio.h>
int num[100] = {5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 4, 7, 7, 5, 9, 5, 0, 3, 8, 7, 5, 8, 1, 5, 8, 6, 1, 8, 3, 0, 3, 7, 9, 2,
                7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3, 8, 5, 1, 6, 3, 4, 6, 7, 0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0,
                1, 0, 0, 9, 4, 8, 0, 9, 1, 2, 8, 5, 0, 2, 5, 3, 3}; // 100个数
const int month[13] = {0, 31, 28, 31, 30, 31, 30, 31,
                       31, 30, 31, 30, 31}; // 平年每月天数
char map[365][5] = {0};                     // 保存日期
int ans = 0;                                // 日期数量

void save(int i, int j, int k, int l) // 保存日期
{
    map[ans][0] = num[i] + '0';
    map[ans][1] = num[j] + '0';
    map[ans][2] = num[k] + '0';
    map[ans][3] = num[l] + '0';
}
int findd(int i, int j, int k, int l, int y) // 查找日期
{
    int flag = 1;
    if (map[y][0] != num[i] + '0')
        flag = 0;
    if (map[y][1] != num[j] + '0')
        flag = 0;
    if (map[y][2] != num[k] + '0')
        flag = 0;
    if (map[y][3] != num[l] + '0')
        flag = 0;
    if (flag == 1)
        return 1;
    else
        return 0;
}
void find(int i, int j, int k, int l) // 查找日期
{
    int flag = 0;
    for (int y = 0; y < ans; y++)
    {
        if (findd(i, j, k, l, y))
            return;
    }
    save(i, j, k, l);
    ans++;
}

int panduan(int i, int j, int k, int l) // 检验是否为合法日期
{
    int flag = 1;
    int y = 0;
    y = num[i] * 10 + num[j];
    int mm = y;
    if (y < 1 || y > 12)
        flag = 0;
    y = num[k] * 10 + num[l];
    if (y < 1 || y > month[mm])
        flag = 0;
    return flag;
}
int main()
{
    int i = 0, j = 0, k = 0, l = 0; // 用于循环
    for (i = 58; i < 100; i++)      // 四层循环遍历月日
    {
        for (j = i + 1; j < 100; j++)
        {
            for (k = j + 1; k < 100; k++)
            {
                for (l = k + 1; l < 100; l++)
                {
                    if (panduan(i, j, k, l))
                        find(i, j, k, l);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}