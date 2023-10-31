#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

long long ans=0,nn=0,maxa=0,t=0,l=0,n=0,m=0;

struct zhalei{
    long long x,y,r;
}a[50005];

struct pailei{
    long long x,y,r;
}b[50005];


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y>>a[i].r;
    }
    for(int i=0;i<m;i++){
        cin>>b[i].x>>b[i].y>>b[i].r;
    }
    for(int i=0;i<n-1;i++){
        if(a[i].x>a[i+1].x){
            zhalei t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
            i-=2;
        }
    }
    for(int i=0;i<n-1;i++){
        if(a[i].y>a[i+1].y&&a[i].x==a[i+1].x){
            zhalei t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
            i-=2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].r<<endl;
    }
    cout<<ans<<endl;
    return 0;
}