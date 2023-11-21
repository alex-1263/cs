#include <iostream>
#include <cstdio>

using namespace std;

int n = 0, t = 0; // flag为标记，n为飞机数量，t为测试用例数量
bool map[15];     // map为标记数组
struct air        // air为飞机结构体
{
    int time;  // time为最早降落时间
    int fuel;  // fuel为最晚降落时间
    int first; // first为降落消耗时间
} plane[15];   // plane为飞机数组

bool dfs(int x, int tt) // x为已降落飞机数量，tt为当前时间
{
    if (x >= n)                 // 如果已降落飞机数量大于等于飞机数量
        return true;            // 返回true
    for (int i = 0; i < n; i++) // 遍历飞机
    {
        if (map[i] == false && tt <= plane[i].fuel) // 如果飞机未降落且当前时间小于等于飞机最晚降落时间
        {
            map[i] = true;                                                    // 标记飞机已降落
            bool tmp = (dfs(x + 1, max(tt, plane[i].time) + plane[i].first)); // 递归,最早降落时间和当前时间的最大值加上降落消耗时间
            map[i] = false;                                                   // 标记飞机未降落
            if (tmp)                                                          // 如果递归返回true
                return true;                                                  // 返回true
        }
    }
    return false; // 返回false
}
int main()
{
    scanf("%d", &t); // 输入测试用例数量
    while (t--)      // 循环测试用例数量次
    {
        scanf("%d", &n);            // 输入飞机数量
        for (int i = 0; i < n; i++) // 遍历飞机
        {
            scanf("%d %d %d", &plane[i].time, &plane[i].fuel, &plane[i].first); // 输入飞机最早降落时间，可飞行时间，降落消耗时间
            plane[i].fuel += plane[i].time;                                     // 飞机最晚降落时间为飞机最早降落时间加上可飞行时间
        }
        if (dfs(0, 0))       // 如果dfs返回true
            printf("YES\n"); // 输出YES
        else                 // 如果dfs返回false
            printf("NO\n");  // 输出NO
    }

    return 0; // 返回0
}