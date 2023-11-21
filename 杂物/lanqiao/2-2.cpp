#include <cstdio>
#include <cmath>

double n = 23333333, ans = 11625907.5798;

int main()
{
    double x, y, sum; // x,y为两个数,sum为两个数的和

    for (x = 1; x <= n / 2; x++) // 循环n/2次
    {
        y = n - x;                                                                    // y为n-x
        sum = -(x * x / n) * (log2(x) - log2(n)) - (y * y / n) * (log2(y) - log2(n)); // sum为x^2/n*log2(x/n)+y^2/n*log2(y/n)
        sum = floor(sum * 10000) / 10000;                                             // sum舍去四位小数之后的数

        if (sum == ans) // 如果sum等于ans
        {
            printf("%.4lf", sum);           // 输出sum
            printf(" %.0lf %.0lf\n", x, y); // 输出x,y
            break;                          // 退出循环
        }
    }
    return 0; // 返回0s
}
