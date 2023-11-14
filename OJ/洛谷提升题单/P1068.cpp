#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int partsort(int *a, int *b, int left, int right) // 快速排序
{
    int key = left;      // 基准值
    while (left < right) // 当left<right时
    {
        while (left < right && a[right] <= a[key]) // 当left<right且a[right]<=a[key]时
        {
            right--; // right减1
        }
        while (left < right && a[left] >= a[key]) // 当left<right且a[left]>=a[key]时
        {
            left++; // left加1
        }
        swap(a[left], a[right]); // 交换a[left]和a[right]
        swap(b[left], b[right]); // 交换b[left]和b[right]
    }
    swap(a[key], a[left]); // 交换a[key]和a[left]
    swap(b[key], b[left]); // 交换b[key]和b[left]
    return left;           // 返回left
}

void quicksort(int *a, int *b, int left, int right) // 快速排序
{
    if (left >= right) // 如果left>=right
    {
        return; // 返回
    }
    int key = partsort(a, b, left, right); // key等于partsort(a,b,left,right)
    quicksort(a, b, left, key - 1);        // 递归调用quicksort(a,b,left,key-1)
    quicksort(a, b, key + 1, right);       // 递归调用quicksort(a,b,key+1,right)
}

int main() // P1068 选课
{
    int cj[5005] = {0}, bh[5005] = {0}; // cj为成绩，bh为编号
    int n = 0, m = 0, sum = 0, x = 0;   // n为人数，m为满分，sum为总人数，x为满分人数
    cin >> n >> m;                      // 输入n和m
    x = m * 1.5;                        // x等于m*1.5
    for (int i = 0; i < n; i++)         // 遍历
    {
        cin >> bh[i] >> cj[i]; // 输入编号和成绩
    }
    quicksort(cj, bh, 0, n - 1); // 调用quicksort(cj,bh,0,n-1)
    while (1)                    // 循环
    {
        if (cj[x - 1] > cj[x]) // 如果cj[x-1]>cj[x]
        {
            break; // 退出循环
        }
        x++; // x加1
    }
    x;                                                   // x等于x
    sum = cj[x - 1];                                     // sum等于cj[x-1]
    cout << sum << ' ' << x << endl;                     // 输出sum和x
    for (int i = 0, left = 0, right = 1; i < x - 1; i++) // 遍历
    {
        if (cj[i] == cj[i + 1]) // 如果cj[i]==cj[i+1]
        {
            right++;        // right加1
            if (i == x - 2) // 如果i==x-2
            {
                sort(bh + left, bh + right); // 调用sort(bh+left,bh+right)
                left = right;                // left等于right
                right++;                     // right加1
            }
        }
        else // 否则
        {
            sort(bh + left, bh + right); // 调用sort(bh+left,bh+right)
            left = right;                // left等于right
            right++;                     // right加1
        }
    }
    for (int i = 0; i < x; i++) // 遍历
    {
        cout << bh[i] << ' ' << cj[i] << endl; // 输出
    }
}
// 总结：快速排序
// 详细过程：
//  1. 从数列中挑出一个元素，称为 “基准”（pivot）；
//  2. 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆放在基准后面（相同的数可以到任一边）。
//     在这个分割结束之后，该基准就处于数列的中间位置。这个称为分割（partition）操作；
//  3. 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
//  4. 递归到最底部时，数列的大小是零或一，也就是已经排序好了。这个算法一定会结束，因为在每次的迭代（iteration）中，
//     它至少会把一个元素摆到它最后的位置去。
//  5. 递归的最大深度为log2n，最坏情况下，每次划分只得到一个比上一次划分少一个元素的子序列，这样需要划分n次，
//     所以最坏情况下时间复杂度为O(nlogn)。
//  6. 快速排序是不稳定的排序算法，因为在分割操作中，与基准值相同的元素可能会被放在与基准值相同的元素的后面，
//     所以相对次序就会改变。
//  7. 快速排序的空间复杂度取决于递归树的深度，而递归树的深度取决于递归调用的次数，也就是取决于划分的次数，
//     最坏情况下需要划分n次，所以空间复杂度为O(n)。
//  8. 快速排序的最坏时间复杂度为O(n^2)，最好时间复杂度为O(nlogn)，平均时间复杂度为O(nlogn)。
//  9. 快速排序是一种原地（in-place）排序算法，不需要额外的存储空间。
//  10. 快速排序是一种不稳定的排序算法。
// 这题的思路:
//  1. 先将成绩从高到低排序，如果有多个人成绩相同，则按照编号从小到大排序。
//  2. 从前往后遍历，找到满足条件的人数。
//  3. 输出满足条件的人数和满分的分数。