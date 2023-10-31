#include<iostream>
#include<cmath>

using namespace std;
long long l=1,w=1,h=1,n=0,ans=0;

int main(){
    cin>>n;
    for(long long i=1;i<=sqrt(n);i++){
        for(long long j=1;j<=sqrt(n);j++){
            if(i*j>n) break;
            for(long long k=1;k<=sqrt(n);k++){
                if(i*j*k>n) break;
                if(i*j*k==n){
                    ans++;
                    cout<<ans<<endl;
                    }
                }
            }
        }



        cout<<ans;
        return 0;
    }
