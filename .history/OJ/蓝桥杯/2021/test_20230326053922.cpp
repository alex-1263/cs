#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int n=0,m=0;
long long ans=0,j=2,x=0;


long long js(long long jj,int n1,int m1){
    if(jj*2<=m1&&(jj-1)*pow(2,n1)>=m1&&m1>0&&n1>0){
        x=(js(jj*2,n1-1,m1)+js(jj-1,n1,m1-1))%1000000007;
    }
    if((jj-1)*pow(2,n1)<m1&&n1>0&&m1>=0){
        x=js(jj*2,n1-1,m1)%1000000007;
    }
    if(jj*2>m1&&m1>0&&n1>=0){
        x=js(jj-1,n1,m1-1)%1000000007;
    }
    if(jj==0&&m==0&&n==0){
        x=1;
    }
    return x;
}

int main(){
    cin>>n>>m;
    ans=js(2,n,m);
    ans%=1000000007;
    cout<<ans<<endl;
    return 0;
}