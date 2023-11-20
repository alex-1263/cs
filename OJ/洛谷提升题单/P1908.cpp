#include <iostream>
#include <cstdio>

using namespace std;

int a[500005] = {0};                     // 用来存储输入的数字
long long sum = 0;                       // 用来存储逆序对的数量
void merge(int left, int mid, int right) //// 用来合并两个有序数组
{
    int b[right - left + 1] = {0};    // 用来存储合并后的数组
    int i = left, j = mid + 1, k = 0; // i是左边数组的指针，j是右边数组的指针，k是合并后数组的指针
    while (i <= mid && j <= right)    // 循环
    {
        if (a[i] > a[j]) // 如果左边的数大于右边的数
        {
            b[k] = a[j];        // 把右边的数放入合并后的数组
            k++;                // 指针后移
            j++;                // 指针后移
            sum += mid - i + 1; // 计算逆序对的数量
        }
        else
        {
            b[k] = a[i]; // 把左边的数放入合并后的数组
            i++;         // 指针后移
            k++;         // 指针后移
        }
    }
    while (i <= mid) // 循环
    {
        b[k] = a[i]; // 把左边的数放入合并后的数组
        i++;         // 指针后移
        k++;         // 指针后移
    }
    while (j <= right) // 循环
    {
        b[k] = a[j]; // 把右边的数放入合并后的数组
        j++;         // 指针后移
        k++;         // 指针后移
    }
    for (int i = left, k = 0; i <= right; i++) // 循环
    {
        a[i] = b[k]; // 把合并后的数组放入原数组
        k++;         // 指针后移
    }
}

void mergesort(int left, int right) // 用来归并排序
{
    if (left < right) // 如果左边小于右边
    {
        int mid = (left + right) / 2; // 计算中间值
        mergesort(left, mid);         // 递归
        mergesort(mid + 1, right);    // 递归
        merge(left, mid, right);      // 合并
    }
}

int main()
{
    int n = 0;                  // n是输入的数字的个数
    cin >> n;                   // 输入
    for (int i = 0; i < n; i++) // 循环
    {
        scanf("%d", &a[i]); // 输入
    }
    mergesort(0, n - 1); // 归并排序

    cout << sum; // 输出
}
// 总结代码思路:
//   1. 本题是一个归并排序的题目，但是要求计算逆序对的数量
//   2. 本题的思路是:
//       1. 用归并排序的思路来排序
//       2. 在合并的时候，如果左边的数大于右边的数，那么逆序对的数量就是左边数组的长度减去左边数组的指针
//       3. 用一个全局变量来存储逆序对的数量
//       4. 在合并的时候，把逆序对的数量加上去
//       5. 最后输出逆序对的数量