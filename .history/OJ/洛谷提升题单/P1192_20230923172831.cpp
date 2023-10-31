#include<iostream>
#include<cstdio>

using namespace std;

long long dp[100005]={0},k;


int main(){
    long long x;
    cin>>x>>k;
    dp[1]=1;
    dp[2]=2;
    for(long long i=2;i<=k;i++){
        dp[i]=dp[i-1]*2;
    }
    for(long long i=k+1;i<=x;i++){
        long long y=0;
        for(long long j=1;j<=k;j++){
            y+=dp[i-j];
        }
        dp[i]=y;
    }
    for(int i=1;i<=x;i++){
    cout<<dp[i]<<endl;    
    }

}