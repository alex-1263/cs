#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    int x,ans=0,a[11]={0},i;
    cin>>x;
    int flag=0;
    if(x<0){
        x=-x;
        flag=1;
    }
    for(i=1;;i++){
        a[i]=x%10;
        x=x/10;
        if(x<=0)
        break;
    }
    for(int j=1,k=i;j<=i;j++,k--){
        ans+=a[j]*pow(10,k-1);
    }
    if(flag==1)
    ans=-ans;
    
    cout<<ans;
}