#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s1[1000005] = {0}, s2[15] = {0}; // s1为文章，s2为单词

int main()
{
    gets(s2);                        // 输入s2
    gets(s1);                        // 输入s1
    char a = ' ';                    // a为空格
    int n2 = strlen(s2);             // n2为s2的长度
    int n1 = strlen(s1);             // n1为s1的长度
    int ans = 0, w = 0, flagw = 0;   // ans为答案，w为单词位置，flagw为标记
    for (int i = 0; i < n1 + 1; i++) // 功能:将大写字母转换为小写字母
    {
        if (s1[i] >= 65 && s1[i] <= 90) // 如果s1[i]是大写字母
            s1[i] += 32;                // s1[i]加32
    }
    for (int i = 0; i < n2 + 1; i++) // 功能:将大写字母转换为小写字母
    {
        if (s2[i] >= 65 && s2[i] <= 90)
            s2[i] += 32;
    }
    for (int i = 0; i < n1; i++) // 遍历
    {
        if (s1[i] == s2[0]) // 如果s1[i]等于s2[0]
        {
            int w1 = i;                    // w1等于i
            if (s1[i - 1] == 32 || i == 0) // 如果s1[i-1]等于空格或i等于0
            {
                int flag = 1;                    // flag等于1
                for (int k = i; k < n2 + i; k++) // 遍历
                {
                    if (s1[k] != s2[k - i]) // 如果s1[k]不等于s2[k-i]
                        flag = 0;           // flag等于0
                }
                if (flag == 1 && s1[i + n2] == 32) // 如果flag等于1且s1[i+n2]等于空格
                {
                    ans++;          // ans加1
                    if (flagw == 0) // 如果flagw等于0
                    {
                        w = w1;    // w等于w1
                        flagw = 1; // flagw等于1
                    }
                }
            }
        }
    }
    if (ans != 0)                // 如果ans不等于0
        cout << ans << " " << w; // 输出ans和w
    else
        cout << -1; // 输出-1
}
// 总结:
// 1.本题的难点在于如何判断单词的位置，以及如何判断单词的个数。
// 2.本题的思路是:先将大写字母转换为小写字母，然后遍历s1，如果s1[i]等于s2[0]，则判断s1[i]到s1[i+n2-1]是否等于s2，如果等于，则ans加1，如果ans等于0，则输出-1，否则输出ans和w。
// 3.本题的代码量较大，但是思路简单。