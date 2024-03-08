#include <iostream>

using namespace std;

int n = 0, ans[5005][5005] = {0};

int main()
{
    int len = 1;
    ans[0][1] = 0;
    ans[1][1] = 1;
    ans[2][1] = 2;
    cin >> n;
    // 高精度加法
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            ans[i][j] = ans[i][j] + ans[i - 1][j] + ans[i - 2][j];
            ans[i][j + 1] = ans[i][j] / 10;
            ans[i][j] = ans[i][j] % 10;
        }
        if (ans[i][len + 1] > 0)
        {
            len++;
        }
    }

    for (int i = len; i >= 1; i--)
    {
        cout << ans[n][i];
    }

    return 0;
}