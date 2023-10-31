#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


int panduan(int n,int x){
    int a[8]={0},i,ans=0;
    a[1]=n/pow(10,6);
    i=pow(10,6);
    a[2]=n%i;
    a[2]=a[2]/pow(10,5);
    i=pow(10,5);
    a[3]=n%i;
    a[3]=a[3]/pow(10,4);
    i=pow(10,4);
    a[4]=n%i;
    a[4]=a[4]/pow(10,3);
    i=pow(10,3);
    a[5]=n%i;
    a[5]=a[5]/100;
    a[6]=n%100;
    a[6]=a[6]/10;
    a[7]=n%10;
    for(i=1;i<8;i++){
        if(a[i]==x)
        ans++;
    }
    if(n<10&&x==0){
        ans-=6;
    }
    else if(n<100&&x==0){
        ans-=5;
    }
    else if(n<1000&&x==0)
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