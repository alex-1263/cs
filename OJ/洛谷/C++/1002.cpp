#include<iostream>
#include<cstdio>

using namespace std;

long long  map[25][25]={0};
int n=0,m=0,mx=0,my=0,ans=0;

void ma(int mx,int my){
    map[mx][my]=-1;
    map[mx-1][my-2]=-1;
    map[mx-2][my-1]=-1;
    map[mx-1][my+2]=-1;
    map[mx-2][my+1]=-1;
    map[mx+1][my-2]=-1;
    map[mx+2][my-1]=-1;
    map[mx+1][my+2]=-1;
    map[mx+2][my+1]=-1;
}

void dfs(int x,int y){
    if(map[x][y]==0){
        if(map[x-1][y]>=0){
            map[x][y]+=map[x-1][y];
        }
        if(map[x][y-1]>=0){
            map[x][y]+=map[x][y-1];
        }
    }
}

int main(){
    cin>>n>>m>>mx>>my;
    map[2][2]=1;
    mx+=2;
    my+=2;
    n+=2;
    m+=2;
    ma(mx,my);
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dfs(i,j);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            printf("%d ",map[i][j]);
        }
        cout<<endl;
    }
    cout<<map[n][m];
    return 0;
}