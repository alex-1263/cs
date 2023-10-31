#include <iostream>

using namespace std;

void Straightsort(int *a, int len, int flag)
{
    int tmp;
    if (a[flag] < a[flag - 1])
    {
        tmp = a[flag];
        a[flag] = a[flag - 1];
        a[flag - 1] = tmp;
        flag--;
        Straightsort(a, len, flag);
    }
    else
    {
        flag++;
        if (flag > len - 1)
            return;
        Straightsort(a, len, flag);
    }
}

int main()
{
    int a[10], i;
    for (i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    Straightsort(a, 10, 1);
    for (i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
}