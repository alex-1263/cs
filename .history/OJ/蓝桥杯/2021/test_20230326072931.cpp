#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

long long n[200005]={0},ans=0,nn=0,x=0,nx=0,l=0;

int main(){
    cin>>nn;
    for(int i=1;i<=nn;i++){
        cin>>n[i];
    }
        for(int i=1;i<=nn;i++){
        cout<<n[i]<<"";
    }
    cout<<endl;
    while(1){
        x=0,nx=0,l=1;
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
    if(x==1){
        break;
    }
        ans++;
        n[nx]=sqrtl((n[nx]/2)+1);
    for(long long i=nx;i<nx+l;i++){
        n[i]=n[nx];
    }

    }
    

    
    
    cout<<ans<<endl;
    return 0;
}