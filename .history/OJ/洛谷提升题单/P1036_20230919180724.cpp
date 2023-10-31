#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n=0,k=0,x[21]={0};
int ans=0;




int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }

}