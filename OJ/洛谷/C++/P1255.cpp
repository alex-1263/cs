#include <iostream>

using namespace std;

int n = 0, ans[5005] = {0};

int main()
{
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    cin >> n;
    for (long long i = 3; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    cout << ans[n] << endl;

    return 0;
}