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
        if(a[i]!=0){
            if(j==n){
                if(j==0){
                    cout<<a[i];
                }
            }
        }
    }


    return 0;
}