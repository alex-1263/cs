#include<iostream>
#include<cstdio>

using namespace std;

int n,m,k,b[1005][1005]={0};
int ans1[1005]={0},ans[1005]={0};

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            ans1[b[j][i]]+=1;
        }
            for(int i=0;i<k;i++){
        if(ans1[k]>0){
            ans[k]++;
            ans1[k]=0;
        }
    }
    }

}