//通俗易懂
#include <iostream>
using namespace std;
long long n = 2021041820210418;
long long arr[1000000];

int main()
{
    int ans = 0;
    int coust = 0;
    long long i = 0;
    long long a, b, c;
    //求出所有约数
    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            arr[coust] = i;
            coust++;
            if (n / i != i)
            {
                arr[coust] = (n / i);
                coust++;
            }
        }
    }
    for (a =0; a < coust; a++)
        for (b = 0; b < coust; b++)
            for (c = 0; c < coust; c++)
            {
                if (arr[a]*arr[b]*arr[c] == n)
                {
                    ans++;
                }
            }
    cout << ans;
    return 0;
}