#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int ans=0;

void dfs(int x,int d,int y){
    if(d==1&&x>=y){
        ans++;
    }
    else{
    for(int i=y;i<=x-(d-1);i++){
        if(x>=y){
            dfs(x-i,d-1,i);
        }
    }        
    }

}


int main(){
    int a,b;
    cin>>a>>b;
    dfs(a,b,1);
    cout << ans;
}