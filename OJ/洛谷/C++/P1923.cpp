#include <bits/stdc++.h>

using namespace std;

int a[10000005], k, n, i;

int partsort(int left, int right)
{
    int key = left;      //取最左边的元素做key
    while (left < right) //左右没有相遇时
    {
        while (left < right && a[key] <= a[right]) //如果右值比key值小，退出循环
        {
            right--;
        }
        while (left < right && a[key] >= a[left]) //如果左值比key值大，退出循环
        {
            left++;
        }
        swap(a[left], a[right]); //交换左右
    }
    swap(a[key], a[left]); //交换key和相遇位置的元素
    return left;           //返回key的位置
}

void quicksort(int left, int right)
{
    if (left >= right)
    {
        return; //区间只有一个数或没有就退出循环；
    }
    int key = partsort(left, right);
    if (k < key)
    {
        quicksort(left, key - 1);
    } //递归调用，对左区间排序
    else if (k > key)
    {
        quicksort(key + 1, right);
    } //递归调用，对右区间排序
    else if (k == key)
    {
        return;
    }
}
int main()
{
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(0, n - 1);
    cout << a[k];
}
