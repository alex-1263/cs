#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct xs
{
    int id, grade, power; // id为编号，grade为排名，power为实力
} list1[100000005];       // 定义一个结构体数组，用来存储选手的信息

bool cmp(xs s1, xs s2)
{ // 定义一个比较函数，用来排序
    if (s1.grade != s2.grade)
    {                               // 如果排名不同，按排名排序
        return s1.grade > s2.grade; // 排名大的在前
    }
    else
    {                         // 如果排名相同
        return s1.id < s2.id; // 排名相同，按编号排序
    }
}

int main()
{                            // 主函数
    int n = 0, r = 0, q = 0; // n为选手数，r为比赛轮数，q为要查询的选手编号
    cin >> n >> r >> q;      // 输入选手数，比赛轮数，要查询的选手编号
    for (int i = 0; i < n * 2; i++)
    {                                 // 输入选手的实力
        scanf("%d", &list1[i].grade); // 输入选手的实力
        list1[i].id = i + 1;          // 给选手编号
    }
    for (int i = 0; i < n * 2; i++)
    {                                 // 输入选手的实力
        scanf("%d", &list1[i].power); // 输入选手的实力
    }
    stable_sort(list1, list1 + 2 * n, cmp); // 按照实力排序
    for (int i = 0; i < r; i++)
    { // 进行r轮比赛
        for (int j = 0; j < n * 2; j += 2)
        {                                                 // 进行一轮比赛
            if (list1[j].power > list1[j + 1].power)      // 如果左边的实力大于右边的实力
                list1[j].grade++;                         // 左边的排名加一
            else if (list1[j].power < list1[j + 1].power) // 如果左边的实力小于右边的实力
                list1[j + 1].grade++;                     // 右边的排名加一
        }
        stable_sort(list1, list1 + 2 * n, cmp); // 按照实力排序
    }

    cout << list1[q - 1].id; // 输出要查询的选手的编号
}
