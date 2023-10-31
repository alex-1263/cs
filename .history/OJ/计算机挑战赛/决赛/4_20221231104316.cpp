#include<iostream>

using namespace std;

int n=0,a=0,b=0,i=0,j=0,ans=0;
int map[10005]={0};

int main(){
    cin >> n >> a >> b ;
    for(i=1;i<=n;i+=a){
        map[i]=1;
    }
    for(i=n;i>=1;i-=b){
        map[i]=1;
    }
    for(i=1;i<=n;i++){
        if(map[i]==1)
        ans++;
    }
    cout << ans << endl;
}