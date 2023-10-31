#include<iostream>
#include<cstdio>

using namespace std;

long long  a[105][105]={0};

int main(){
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[0][i];
        a[i][0]=a[0][i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            a[i][j]=a[0][j]+a[i][0];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=n;k++){
                if(a[i][j]==a[k][0])
                ans++;
            }
        }
    }
    cout<<ans;
}