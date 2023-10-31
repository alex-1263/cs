#include<iostream>
#include<cstdio>

using namespace std;

int a[2147483648]={0};

int main(){
    int i;
    for(i=0;;i++){
        cin>>a[i];
        if(a[i]==0)
        break;
    }
    for(int j=i;j>=0;j--){
        if(a[j]!=0)
        cout<<a[j]<<" ";
    }
}