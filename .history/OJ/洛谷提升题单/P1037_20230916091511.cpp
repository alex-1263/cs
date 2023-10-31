#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    int x,ans=0,a[11]={0},i;
    cin>>x;
    for(i=1;;i++){
        a[i]=x%10;
        x=x/10;
        if(x<=0)
        break;
    }
    for(int j=i;j>0;j--){
        ans+=1*pow(10,j);
    }
    cout<<ans;
}