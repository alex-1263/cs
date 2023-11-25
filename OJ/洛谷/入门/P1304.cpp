#include <iostream>
#include <cmath>
using namespace std;

int panduan(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; x > 2 && i < x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2)
    {
        for (int j = 2; j < i; j++)
        {
            if (panduan(j))
            {
                if (panduan(i - j))
                {
                    cout << i << "=" << j << "+" << i - j << endl;
                    break;
                }
            }
        }
    }
    return 0;
}