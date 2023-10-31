#include<iostream>
#include<cstdio>

using namespace std;

int ans=0;

void dfs(int x,int d,int y){
    if(d==1){
        ans++;
        return;
    }
    for(int i=1;i<=x-d;i++){
        if(x>=y){
            dfs(x-i,d-1,i);
        }
    }
}


int main(){
    int a;
    cin>>a;
    
}