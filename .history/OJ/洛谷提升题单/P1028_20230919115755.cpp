#include<iostream>
#include<cstdio>

using namespace std;

int dg(int x){
    int ans=0;
    for(int i=1;i<(x/2);i++){
        ans+=dg(i);
    }
    return ans;

}


int main(){
    int x=0;
    cin>>x;
    cout<<dg(x);
    return 0;

}