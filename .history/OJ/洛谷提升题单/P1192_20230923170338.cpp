#include<iostream>
#include<cstdio>

using namespace std;

int dp(int x,int k){
    if(x==0){
        return 1;
    }
    else if(x<0){
        return 0;
    }
    int y=0;
    for (int i=1;i<=k;i++){
        if(x-i>=0){
        y+=dp(x-i,k);
        y=y%100003;            
        }
        else{
        break;
        }

    }
    return y;
}


int main(){
    int a,b;
    cin>>a>>b;
    cout<<dp(a,b);

}