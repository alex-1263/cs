#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int n=0,m=0;
long long ans=0,j=0,x=0;

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
    dp[n][m-1][2]%=1000000007;
    cout<<dp[n][m-1][2]<<endl;
    return 0;
}