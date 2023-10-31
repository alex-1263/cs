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
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans1[b[j][i]]++;
        }
        for(int z=1;z<=k;z++){
            if(ans1[z]>0){
            ans[z]++;
            ans1[z]=0;
            }
        }
    }
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<b[j][i]<<" ";
        }
        cout<<"\n";
    }   

        for(int i=1;i<=k;i++){
        cout<<ans[i]<<" ";
        }
}