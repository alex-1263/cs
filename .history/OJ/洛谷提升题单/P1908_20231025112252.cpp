#include<iostream>
#include<cstdio>

using namespace std;

int a[500005]={0};
long long sum=0;
void merge(int left,int mid,int right){
    int b[right-left+1]={0};
    int i=left,j=mid+1,k=0;
    while(i<=mid&&j<=right){
        if(a[i]<=a[j]){
            b[k]=a[i];
            k++;
            i++;
        }
        else{
            b[k]=a[j];
            k++;
            j++;
            sum++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;

    }
    while(j<=right){
        b[k]=a[j];
        j++;
        k++;
    }
    for(int i=left,k=0;i<=right;i++){
        a[i]=b[k];
        k++;
    }
}

void mergesort(int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(left,mid);
        mergesort(mid+1,right);
        merge(left,mid,right);
    }
}

int main(){
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<sum;
}