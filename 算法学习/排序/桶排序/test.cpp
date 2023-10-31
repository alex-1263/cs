#include <iostream>

using namespace std;

int main()
{
    int a[11], i = 0, j = 0, t = 0;
    for (i = 0; i < 11; i++)
    {
        a[i] = 0; //初始化为0
    }
    for (i = 0; i < 5; i++) //循环读入5个数
    {
        cin >> t; //将读入的数存入t
        a[t]++;   //将下标为t的数+1
    }

    for (i = 0; i < 11; i++) //从0到10进行遍历
    {
        for (j = 1; j <= a[i]; j++) //将数组里面的成绩输出
        {
            cout << i << " ";
        }
    }
    return 0;
}