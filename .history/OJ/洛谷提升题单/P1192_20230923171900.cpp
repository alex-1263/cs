#include<iostream>
#include<cstdio>

using namespace std;

long long dp[100005]={0},sum[100005]={0},k;


int main(){
    int x;
    cin>>x>>k;
    dp[1]=1;
    sum[1]=1;
    dp[2]=2;
    sum[2]=3;
    for(int i=3;i<=k;i++){
        dp[i]=sum[i-1]+1;
        sum[i]=sum[i-1]+dp[i];
    }

}