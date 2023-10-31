#include<iostream>
#include<cstdio>

using namespace std;

long long dp[100005]={0},sum[100005]={0},k;


int main(){
    long long x;
    cin>>x>>k;
    dp[1]=1;
    sum[1]=1;
    dp[2]=2;
    sum[2]=3;
    for(long long i=3;i<=k;i++){
        dp[i]=sum[i-1]+1;
        sum[i]=sum[i-1]+dp[i];
    }
    for(long long i=k+1;i<=x;i++){
        long long y=0;
        for(long long j=1;j<=k;j++){
            y+=dp[i-j];
        }
        dp[i]=y;
    }
    cout<<dp[x];
}