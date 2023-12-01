#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int find(int n, const vector<int> &strengths)
{
    if (n <= 1)
    {
        // 至少需要两名战士
        return -1;
    }

    // 先对战士的战斗力进行排序
    vector<int> sortedStrengths = strengths;
    sort(sortedStrengths.begin(), sortedStrengths.end());

    // 初始最小差值为最大整数
    int minDifference = INT_MAX;

    // 找出相邻两名战士的战斗力差值中的最小值
    for (int i = 1; i < n; ++i)
    {
        int difference = sortedStrengths[i] - sortedStrengths[i - 1];
        minDifference = min(minDifference, difference);
    }

    return minDifference;
}

int main()
{
    int n;
    cin >> n;

    vector<int> strengths(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> strengths[i];
    }

    int result = find(n, strengths);

    cout << result << endl;

    return 0;
}
