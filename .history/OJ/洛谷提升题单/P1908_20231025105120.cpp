#include<iostream>
#include<cstdio>

using namespace std;

int a[500005]={0};

int main(){
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}