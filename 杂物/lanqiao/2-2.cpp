#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int mian()
{
    long long x = 1, n = 23333333, y;
    double ans = 11625907.5798, sum = 0;
    for (x = 1; x <= n / 2 + 1; x++)
    {
        y = n - x;
        sum = double(x * x / n) * (log2(double(x / n))) + double(y * y / n) * (log2(double(y / n)));
        if (sum == ans)
        {
            cout << x << endl;
            break;
        }
    }
    return 0;
}