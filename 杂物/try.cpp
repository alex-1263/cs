//测试github copilot
#include<iostream>
using namespace std;
//一个归并排序函数,每一行给出注释
void merge(int a[],int left,int mid,int right)//归并函数，将两个有序数组合并成一个有序数组
{
    int i=left;//左边数组的起始位置
    int j=mid+1;//右边数组的起始位置
    int k=0;//临时数组的起始位置
    int *temp=new int[right-left+1];//临时数组
    while(i<=mid&&j<=right)//将两个有序数组合并成一个有序数组
    {
        if(a[i]<=a[j])//将较小的数放入临时数组
        {
            temp[k++]=a[i++];//将左边数组的数放入临时数组
        }
        else//将较小的数放入临时数组
        {
            temp[k++]=a[j++];//将右边数组的数放入临时数组
        }
    }
    while(i<=mid)//将左边数组剩余的数放入临时数组
    {
        temp[k++]=a[i++];//将左边数组的数放入临时数组
    }
    while(j<=right)
    {
        temp[k++]=a[j++];//将右边数组的数放入临时数组
    }
    for(int i=0;i<k;i++)
    {
        a[left+i]=temp[i];//将临时数组的数放入原数组
    }
    delete []temp;//释放临时数组
}

//一个快速排序函数
void quicksort(int a[],int left,int right)//快速排序函数
{
    if(left>=right)//递归结束条件
    {
        return;//返回
    }
    int i=left;
    int j=right;
    int key=a[left];
    while(i<j)
    {
        while(i<j&&a[j]>=key)
        {
            j--;
        }
        a[i]=a[j];
        while(i<j&&a[i]<=key)
        {
            i++;
        }
        a[j]=a[i];
    }
    a[i]=key;
    quicksort(a,left,i-1);
    quicksort(a,i+1,right);
}
int main()
{
    cout<<"Hello World!"<<endl;
    return 0;
}