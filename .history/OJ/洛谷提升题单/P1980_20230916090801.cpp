#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int panduan(int n,int x){
    int ans,a;
    for(int i=1;i<8;i++){
        a=n%10;
        if(a==x)
        ans++;
        n=n/10;
        if(n==0)
        break;
    }
    return ans;
}


int main(){
    int n=0,ans=0,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        ans+=panduan(i,x);
    }
    cout<<ans;
}