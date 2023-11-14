#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s[100005];      // 用来存储名字
int map[100005] = {0}; // 用来存储方向

int main()
{
    int n = 0, m = 0, w = 0, a, b; // n是玩具小人的个数，m是指令的数量，w是现在的位置，a是方向，b是步数
    cin >> n >> m;                 // 输入
    for (int i = 0; i < n; i++)    // 循环
    {
        cin >> map[i] >> s[i]; // 输入
    }
    for (int i = 0; i < m; i++) // 循环
    {
        cin >> a >> b;   // 输入
        if (map[w] == a) // 如果方向相同
        {
            w = (w - b) % n; // 计算
            if (w < 0)       // 如果小于0
                w += n;      // 加上n
        }
        else // 如果方向不同
        {
            w = (w + b) % n; // 计算
        }
    }
    cout << s[w]; // 输出
}