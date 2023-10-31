#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int n=0,m=0;
long long ans=0,j=0,x=0;

long long dp[105][105][105]={0};
dp[0][0][0]=1;
int main(){
    cin>>n>>m;

    ans%=1000000007;
    cout<<ans<<endl;
    return 0;
}