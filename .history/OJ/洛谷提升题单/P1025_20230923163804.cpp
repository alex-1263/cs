#include<iostream>
#include<cstdio>

using namespace std;


int dfs(int x,int d,int y){
    if(d==1){
        return 1;
    }
    for(int i=1;i<=x-d;i++){
        if(x>=y){
            return dfs(x-i,d-1,i);
        }
    }
}


int main(){
    
    cout<<dfs(7,3,1)
}