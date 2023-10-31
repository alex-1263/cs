#include <iostream>
using namespace std;
int partsort(int *a, int left, int right)
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
void quicksort(int *a, int left, int right)
{
    if (left >= right)
    {
        return; //区间只有一个数或没有就退出循环；
    }
    int key = partsort(a, left, right);
    quicksort(a, left, key - 1);  //递归调用，对左区间排序
    quicksort(a, key + 1, right); //递归调用，对右区间排序
}
int main()
{
    int a[11], i = 0, j = 0, t = 0, k = 0;
    for (i = 0; i < 11; i++)
    {
        a[i] = 0;
    }
    for (i = 0; i < 11; i++)
    {
        cin >> a[i];
    }
    quicksort(a, 0, 10);
    for (i = 0; i < 11; i++)
    {
        cout << a[i] << " ";
    }
}