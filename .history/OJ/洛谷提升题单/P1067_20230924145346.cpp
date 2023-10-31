#include<iostream>
#include<cstdio>

using namespace std;

int a[105]={0};


int main(){
    int n=0;
    cin>>n;
    for(int i=0;i<n+1;i++){
        cin>>a[i];
    }
    for(int i=0,j=n;i<n+1;i++,j--){
        if(j==n&&n>0){
            if(a[i]==1){
                cout<<"x^"<<j;
            }
        }
    }


    return 0;
}