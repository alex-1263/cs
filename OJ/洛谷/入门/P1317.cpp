#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int a0 = 0;
    int a1 = 0;
    int a = 0;
    int ans = 0;
    int flag = 0;
    int flag1 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a0 > a1)
        {
            flag = 1;
        }
        else if (a0 < a1)
        {
            flag = 0;
        }
        if (flag1 == 1 && flag == 0)
        {
            ans++;
        }
        flag1 = flag;
        a0 = a1;
        a1 = a;
    }
    cout << ans << endl;
    return 0;
}