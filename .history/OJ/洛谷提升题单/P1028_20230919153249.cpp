#include<iostream>
#include<cstdio>

using namespace std;

int dg(int x){
    int ans=0;
    if(x==1){
        ans=1;
        return ans;
    }
    for(int i=(x/2);i>=1;i--){
        ans+=dg(i);
    }
    if(x!=1){
        ans++;
    }
    return ans;

}


int main(){
    int x=0;
    cin>>x;
    cout<<dg(x);
    return 0;

}