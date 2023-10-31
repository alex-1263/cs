#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

long long n[20005]={0},ans=0,nn=0,x=0,nx=0,l=0,flag=0;

int main(){
    cin>>nn;
    flag=nn;
    for(int i=1;i<=nn;i++){
        cin>>n[i];
    }
    while(1){
        x=0,nx=1,l=1;
        for(long long i=1;i<=nn;i++){
        if(n[i]>x){
            x=n[i];
            nx=i;
            l=1;
        }
        if(n[i-1]==n[i]&&x==n[i]){
            l++;
        }
    }
        ans++;
    for(long long i=nx;i<=nx+l-1;i++){
        n[i]=sqrtl((n[i]/2)+1);
        if(n[i]==1){
            flag--;
        }
    }
    if(flag==0){
        break;
    }
    for(long long i=1;i<=nn;i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
        cout<<ans<<endl;
    }

    cout<<ans<<endl;
    return 0;
}