#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    long long a,b,c,n,d,ans;
    cin>>a>>b>>n;
    d=b-a;
    ans=n*a+n*(n-1)*d/2;
    cout<<ans;
}