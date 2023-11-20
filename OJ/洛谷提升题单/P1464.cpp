#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

long long w(long long a, long long b, long long c) // 递归函数
{

    if (a <= 0 || b <= 0 || c <= 0) // 如果有一个小于等于0
    {
        return 1; // 返回1
    }
    else if (a > 20 || b > 20 || c > 20) // 如果有一个大于20
    {
        return w(20, 20, 20); // 返回w(20,20,20)
    }
    else if (a == b)
    {
        return pow(2, a); // 返回2^a
    }
    else if (b == c && b > a)
    {
        return pow(2, a);
    }
    else if (a == (b - 1) && b == (c - 1))
    {
        return pow(2, a);
    }
    else if (a < b && b < c)
    {
        return (w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c));
    }
    return (w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1));
}

int main()
{
    long long a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        printf("w(%lld, %lld, %lld) = ", a, b, c);
        cout << w(a, b, c) << endl;
    }
}