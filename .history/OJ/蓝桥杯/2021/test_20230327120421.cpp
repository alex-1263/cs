#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

long long n[7][200005]={0},ans=0,nn=0,maxa=0,t=0;

int main(){
    cin>>nn;
    for(int i=1;i<=nn;i++){
        cin>>n[0][i];
    }

    for(int i=0;i<=7;i++){
        for(int j=1;j<=nn;j++){
                t=n[i][j];
                if(t>1){
                n[i+1][j]=sqrtl((t/2)+1);
                ans++;
                };
        }
    }
    for(int i=0;i<=7;i++){
        for(int j=1;j<nn;j++){
           if(n[i][j]==n[i][j+1]&&n[i][j]>1)
           ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}