#include<iostream>
#include<cmath>

using namespace std;
long long l=1,w=1,h=1,n=0,ans=0,i,j,k;

int main(){
    cin>>n;
    for(i=1;i<=sqrtl(n);i++){
        for( j=1;j<=sqrtl(n);j++){
            if(i*j>n) break;
            for(k=1;k<=sqrtl(n);k++){
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
