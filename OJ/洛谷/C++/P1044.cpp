#include <iostream>

using namespace std;

long long a[20][20] = {0};

void dp(int push, int pop)
{
    if (push == 0)
    {
        a[push][pop] = 1;
        return;
    }
    else if (pop == 0)
    {
        if (a[push][pop] == 0)
        {
            dp(push - 1, pop + 1);
            a[push][pop] = a[push - 1][pop + 1];
        }
    }
    else if (push > 0)
    {
        if (a[push][pop] == 0)
        {
            dp(push - 1, pop + 1);
            dp(push, pop - 1);
            a[push][pop] = a[push - 1][pop + 1] + a[push][pop - 1];
        }
    }
}
int main()
{
    int n = 0;
    cin >> n;
    dp(n, 0);
    cout << a[n][0];
    return 0;
}