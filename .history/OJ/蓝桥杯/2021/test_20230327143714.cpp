#include<iostream>

using namespace std;
long long l=1,w=1,h=1,n=0,ans=0;

int main(){
    cin>>n;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            for(long long k=1;k<=n;k++){
                if(i*j*k==n){
                    ans++;
                    }
                }
            }
        }



        cout<<ans;
        return 0;
    }
