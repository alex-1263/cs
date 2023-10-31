#include<iostream>
#include<cstdio>

using namespace std;

long long fb[9706150]={0},k;



int main(){
    long long ans=0;
    cin>>k;
    fb[1]=0,fb[2]=1;
    for(int i=3;;i++){
        fb[i]=(fb[i-1]+fb[i-2])%k;
        if(fb[i]==1&&fb[i-1]==0){
            ans=i-2;
            break;
        }
    }
    cout<<ans;
}