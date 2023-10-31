#include<iostream>
#include<cstdio>

using namespace std;

int map[1005][1005]={0};
int r=0,ans=0;

void dp(int i,int j){
    if(map[i-1][j-1]>=map[i-1][j]){
        map[i][j]+=map[i-1][j-1];
    }
    else{
        map[i][j]+=map[i-1][j];
    }
}

int main(){
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            dp(i,j);
        }
    }
    
    for(int i=1;i<=r;i++){
        if(map[r][i]>=ans){
            ans=map[r][i];
        }
    }
    cout<<ans;
    return 0;
}