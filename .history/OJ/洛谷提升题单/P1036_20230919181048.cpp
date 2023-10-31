#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n=0,k=0,x[21]={0};
int ans=0;

int panduan(int x){
    int flag=1;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            flag=0;
            break;
        }
    }
    return flag;
}


int dfs(int d){
    
}


int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }

}