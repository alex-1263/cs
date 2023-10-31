#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int map[105][1005]={0};
int thing[105][2]={0};
int t=0,m=0;

void dp(int i,int j){
    if(j-thing[i][1]>=0){
        map[i][j]=max(map[i-1][j],map[i-1][j-thing[i][1]]+thing[i][2]);    
    }
    else{
        map[i][j]=map[i-1][j];
    }
    
}

int main(){
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&thing[i][1],&thing[i][2]);
    }
    for(int i=thing[1][1];i<=t;i++){
        map[1][i]=thing[1][2];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t;j++){
            dp(i,j);
        }
    }
    cout<<map[m][t];
}