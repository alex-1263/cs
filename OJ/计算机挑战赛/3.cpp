#include <iostream>

using namespace std;

int n[205][205]={0},i=0,j=0,x=0,ans=0;

int main(){
    cin >> x;
    for(i=1;i<=x;i++){
        for(j=1;j<=x;j++){
            cin >>n[i][j];
        }
    }
    for(i=1,j=1;i<=x;i++){
    ans+=n[i][j];
    }
     for(i=1,j=x;i<=x;i++){
    ans+=n[i][j];
    }
    for(j=1,i=1;j<=x;j++){
    ans+=n[i][j];
    }
    for(j=1,i=x;j<=x;j++){
    ans+=n[i][j];
    }
    ans=ans-n[1][1]-n[1][x]-n[x][1]-n[x][x];
    cout<<ans;
}