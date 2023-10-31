#include<iostream>
#include<cstdio>

using namespace std;


int a[200005]={0},b[200005]={0},g[200005]={0},k[200005]={0};


int main(){
    int n=0,x=0,y=0,flag=1;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>g[i]>>k[i];
    }
    cin>>x>>y;
    for(int i=n;i>=1;i--){
        if(x>=a[i]&&x<=a[i]+g[i]){
            if(y>=b[i]&&y<=b[i]+k[i]){
                cout<<i;
                flag=0;
                break;
            }
        }
    }

    return 0;
}