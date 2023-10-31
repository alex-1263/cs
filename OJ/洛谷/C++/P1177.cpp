#include <bits/stdc++.h>

using namespace std;

int partsort(int *a, int left, int right);
void Straightsort(int *a, int len, int flag);
void quicksort(int *a, int left, int right);

int partsort(int *a, int left, int right)
{
    int key = left;
    while (left < right)
    {
        while (left < right && a[key] <= a[right])
        {
            right--;
        }
        while (left < right && a[key] >= a[left])
        {
            left++;
        }
        swap(a[left], a[right]);
    }
    swap(a[key], a[left]);
    return left;
}

void Straightsort(int *a, int len, int flag)
{
    if (a[flag] < a[flag - 1])
    {
        swap(a[flag], a[flag - 1]);
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

void quicksort(int *a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int key = partsort(a, left, right);

    quicksort(a, left, key - 1);

    quicksort(a, key + 1, right);
}

int a[100005];

int main()
{
    int n = 0, m = 0, i = 0, j = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}