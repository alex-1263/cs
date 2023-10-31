#include <iostream>

using namespace std;

int main()
{
    int a[5], i = 0, j = 0, t = 0;

    for (i = 0; i < 5; i++)
    {
        a[i] = 0; //初始化
    }

    for (i = 0; i < 5; i++)
    {
        cin >> a[i]; //输入数据
    }
    for (i = 0; i < 4; i++) //外层循环次数是n-1
    {
        for (j = 0; j < 4; j++) //内层循环次数是n-1
        {
            if (a[j] < a[j + 1]) //如果前面的数比后面的数小将其交换
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        cout << a[i] << " "; //遍历输出
    }

    return 0;
}