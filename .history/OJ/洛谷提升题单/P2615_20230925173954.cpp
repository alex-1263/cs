#include<iostream>
#include<cstdio>

using namespace std;

int map[45][45]={0};

int main(){
    int n=0,xk=0,yk=0;
    cin>>n;
    map[1][n/2+1]={1};
    yk=1;xk=n/2+1;
    for(int k=2;k<=n*n;k++){
        if(yk==1&&xk!=n){
            yk=n,xk++;
        }
        else if(yk!=1&&xk==n){
            xk=1,yk--;
        }
        else if(yk==1&&xk==n){
            yk++;
        }
        else if(yk!=1&&xk!=1){
            if(map[yk-1][xk+1]==0){
                yk--,xk++;
            }
            else{
                yk++;
            }
        }
        map[yk][xk]=k;
    }
}