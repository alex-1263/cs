#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;

ll n,m,ans;
ll f[105][105][105];

int main(){

    cin>>n>>m;

    f[0][0][2]=1;//不管怎么样必然会有一种初始方案。
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=m;k++){
                //遇到花
                if(j&&k)f[i][j][k]=(f[i][j][k]+f[i][j-1][k+1])%MOD;
                //遇到店
                if(i&&k%2==0)f[i][j][k]=(f[i][j][k]+f[i-1][j][k/2])%MOD;
            }
        }
    }
    //因为没有酒遇到花是不合法的，所以循环的时候没有执行f[][m][0]的所有情况
    //因为最后一步必须是遇到花，所以f[n][m-1][1]的值等于我们想要的f[n][m][0]
    cout<<f[n][m-1][1];
    return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

long long ans=0,n=0,m=0;

long long dp[105][105][105]={0};

int main(){
    cin>>n>>m;
    dp[0][0][2]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(i>0&&k%2==0)
                dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k/2])%1000000007;
                if(j>0&&k>0)
                dp[i][j][k]=(dp[i][j][k]+dp[i][j-1][k+1])%1000000007;
            }
        }
    }
    dp[n][m-1][1]%=1000000007;
    cout<<dp[n][m-1][1]<<endl;
    return 0;
}
*/