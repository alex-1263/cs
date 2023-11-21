#include <stdio.h>

int main()
{
    int n = 0;                            // n为输入的数
    int a[10005] = {0};                   // a数组存储输出的数
    scanf("%d", &n);                      // 输入n
    for (int i = 0; i < (n / 2) + 1; i++) // 循环n/2+1次
    {
        a[i] = (n - i - 1) * 2; // a[i]为输出的数
    }
    if (n % 2 == 0) // 如果n为偶数
    {
        for (int i = 0; i < n / 2; i++) // 循环n/2次
        {
            printf("%d\n", a[i]); // 输出a[i]
        }
        for (int i = n / 2 - 1; i >= 0; i--) // 循环n/2次
        {
            printf("%d\n", a[i]); // 输出a[i]
        }
    }
    else // 如果n为奇数
    {
        for (int i = 0; i < n / 2; i++) // 循环n/2次
        {
            printf("%d\n", a[i]); // 输出a[i]
        }
        for (int i = n / 2; i >= 0; i--) // 循环n/2+1次
        {
            printf("%d\n", a[i]); // 输出a[i]
        }
    }
    return 0;
}