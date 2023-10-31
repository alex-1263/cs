#include<iostream>
#include<cstdio>

using namespace std;

int a[105][105]={0};

int main(){
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[0][i];
        a[i][0]=a[0][i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}