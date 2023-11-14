#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int a = 123, b, c;               // a,b,c分别代表三个数
int panduan(int a, int b, int c) // 判断是否符合条件
{
    int a1 = a / 100, a2 = a % 100, a3 = a % 10; // a1,a2,a3分别代表a的百位，十位，个位
    a2 = a2 / 10;                                // a2为a的十位
    int b1 = b / 100, b2 = b % 100, b3 = b % 10; // b1,b2,b3分别代表b的百位，十位，个位
    b2 = b2 / 10;                                // b2为b的十位
    int c1 = c / 100, c2 = c % 100, c3 = c % 10; // c1,c2,c3分别代表c的百位，十位，个位
    c2 = c2 / 10;                                // c2为c的十位
    int flag[11] = {0};                          // flag数组用来判断是否有重复的数字
    flag[a1]++;                                  // flag数组的下标代表数字，flag数组的值代表数字出现的次数
    flag[a2]++;                                  // 如果flag数组的值大于1，说明有重复的数字
    flag[a3]++;                                  // 如果flag数组的值等于0，说明没有这个数字
    flag[b1]++;                                  // 如果flag数组的值等于1，说明有这个数字
    flag[b2]++;
    flag[b3]++;
    flag[c1]++;
    flag[c2]++;
    flag[c3]++;
    int flag1 = 1;               // flag1为1代表没有重复的数字
    for (int i = 1; i < 10; i++) // 判断flag数组的值是否等于1
    {
        if (flag[i] != 1) // 如果flag数组的值不等于1，说明有重复的数字
        {
            flag1 = 0; // flag1为0代表有重复的数字
            break;     // 跳出循环
        }
    }
    return flag1; // 返回flag1的值
}
int main() // 主函数
{
    for (a = 123; a < 335; a++) // a的范围为123到333
    {
        b = 2 * a;                 // b为a的两倍
        c = 3 * a;                 // c为a的三倍
        if (panduan(a, b, c) == 1) // 如果符合条件
        {
            printf("%d %d %d\n", a, b, c); // 输出a,b,c
        }
    }
}
// 总结：判断是否有重复的数字，用flag数组，flag数组的下标代表数字，flag数组的值代表数字出现的次数
