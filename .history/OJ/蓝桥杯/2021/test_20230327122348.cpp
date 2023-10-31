#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

long long n[7][200005]={0},ans=0,nn=0,maxa=0,t=0,l=0;

int main(){
    cin>>nn;
    for(int i=1;i<=nn;i++){
        cin>>n[0][i];
    }

    for(int i=0;i<=7;i++){
        maxa=0;
        for(int j=1;j<=nn;j++){
                t=n[i][j];
                n[i+1][j]=t;
                if(maxa<t)maxa=t;
                if(t>1){
                n[i+1][j]=sqrtl((t/2)+1);
                ans++;
                cout<<endl<<"ans:"<<ans<<" ";
                };
        }
        if(maxa==1)break;
        l++;
        }
        for(int i=0;i<=7;i++){
            for(int j=1;j<=nn;j++){
                cout<<n[i][j]<<" ";
            }
            cout<<endl;
        }
    for(int i=0;i<=7;i++){
        maxa=0;
        for(int j=1;j<nn;j++){
            t=n[i][j];
            if(maxa<t)
            maxa=t;
            for(int k=i;k<=;k++){
                if(t==1)
                break;
                if(t==n[k][j+1]){
                    ans--;
                }
            }
        }
        if(maxa==1)break;
    }
    cout<<"ANS:"<<ans<<endl;
    return 0;
}