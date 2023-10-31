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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=a[0][j]+a[i][0];
        }
    }
    a[1][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(a[i][j]==a[k][0])
                ans++;
            }
        }
    }
}