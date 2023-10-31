#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

long long n[20005]={0},ans=0,nn=0,x=0,nx=0,l=0,flag=0;

int main(){
    cin>>nn;
    falg=nn;
    for(int i=1;i<=nn;i++){
        cin>>n[i];
    }
    while(1){
        for(long long i=1,x=n[1],nx=1;i<=nn;i++){
        if(n[i]>x){
            x=n[i];
            nx=i;
            l=1;
        }
        if(n[i-1]==n[i]&&x==n[i]){
            l++;
        }
    }
    for(long long i=nx;i<=nx+l;i++){
        n[i]=sqrtl((n[i]/2)+1);
    }
    ans++;
    x=0;
    for(long long i=1;i<=nn;i++){
        if(n[i]>1){
            x++;
            break;
        }
    }
    if(x==0){
        break;
    }
    }
    cout<<ans;
    return 0;
}