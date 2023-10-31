#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n=0,k=0,x[21]={0},map[21]={0};
int ans=0;

void panduan(int x){
    int flag=1;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            flag=0;
            break;
        }
    }
    if(flag==1){
        ans++;
        cout<<x<<endl;
    }

}


void dfs(int d,int sum){
    if(d==k){
        panduan(sum);
    }
    for(int i=0;i<n;i++){
        if(map[i]==0){
            map[i]=1;
            dfs(d++,sum+x[i]);
            map[i]=0;
        }
    }

}


int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);
    dfs(0,0);
    cout<<"K="<<k<<endl;
    cout<<ans;

}