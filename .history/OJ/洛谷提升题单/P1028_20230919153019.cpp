#include<iostream>
#include<cstdio>

using namespace std;

int dg(int x){
    int ans=0;
    if(x==1){
        ans=1;
        return ans;
    }
    if(x==2){
        ans=2;
        return ans;        
    }
    if(x==3){
        ans=2;
        return ans;
    }
    if(x==4){
        ans=3;
        return ans;
    }
    if(x==5){
        ans=3;
        return ans;
    }
    if(x==6){
        ans=6;
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