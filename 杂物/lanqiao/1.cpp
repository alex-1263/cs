#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n = 0;
    int a[10005] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = (n - i - 1) * 2;
    }
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            printf("%d\n", a[i]);
        }
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
    }
    else
    {
        for (int i = 0; i < (n / 2) + 1; i++)
        {
            printf("%d\n", a[i]);
        }
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
    }
}