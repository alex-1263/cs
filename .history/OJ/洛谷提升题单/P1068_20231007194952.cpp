#include<iostream>
#include<cstdio>

using namespace std;



int partsort(int *a,int *b,int left,int right){
        int key=left;
        while(left<right){
            while(left <right &&a[right]<=a[key]){
                right--;
            }            
            while(left <right&&a[left]>=a[key]){
                left++;
            }
            swap(a[left],a[right]);
            swap(b[left],b[right]);
            return left;
        }
}

int quicksort(int *a,int *b,int left,int right){
    if(left>=right){
        return ;
    }
    int key=partsort(a,b,left,right);
    quicksort(a,b,left,key-1);
    quicksort(a,b,key+1,right);
}

int main(){
    int cj[5005]={0},bh[5005]={0};
    int n=0,m=0,sum=0,x=0;    
    cin>>n>>m;
    m*=1.5;
    cout<<m;
    for(int i=0;i<n;i++){
        cin>>bh[i]>>cj[i];
    }
    quicksort(cj,bh,0,n-1);
    for(int i=0;i<n;i++){
        cout<<bh[i]<<cj[i]<<endl;
    }
    


}