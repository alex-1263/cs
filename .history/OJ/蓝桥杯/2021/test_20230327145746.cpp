#include<iostream>
#include<cmath>

using namespace std;
long long l=1,w=1,h=1,n=0,ans=0,i=0,nn=0,j,k,m[1000]={0};

int main(){
    cin>>n;
    for(i=1;i<=sqrt(n)+1;i++){
        if(n%i==0)
        {
            m[nn]=i;
            nn++;
        }
    }
    for(i=1;i<nn;i++)
    for(j=i;j<nn;j++)
    for(k=k;k<nn;k++)
    {
        if(m[i]*m[j]*m[k]==n)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
