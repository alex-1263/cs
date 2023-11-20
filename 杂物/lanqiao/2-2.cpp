#include <iostream>
#include <cmath>
using namespace std;

double n = 23333333, ans = 11625907.5798;

int main()
{
    double x, y, x1, y1, sum;

    for (x = 1; x <= n / 2; x++)
    {
        y = n - x;
        sum = -(x * x / n) * (log2(x) - log2(n)) - (y * y / n) * (log2(y) - log2(n));
        // double sum舍去四位小数之后的数,不用四舍五入
        sum = floor(sum * 10000) / 10000;

        if (sum == ans)
        {
            printf("%.4lf", sum);
            printf(" %.0lf %.0lf\n", x, y);
            break;
        }
    }
    return 0;
}
