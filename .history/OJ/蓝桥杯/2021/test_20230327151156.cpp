#include<iostream>
#include<cmath>

using namespace std;
long long l=1,w=1,h=1,n=0,ans=0,i=0,nn=0,j,k,m[100000000]={0};
int main(){
    n=2021041820210418;
    for(i=1;i<=sqrt(n)+1;i++){
        if(n%i==0)
        {
            m[nn]=i;
            nn++;
        }
    }


    for(i=0;i<nn;i++)
    for(j=0;j<nn;j++)
    for(k=0;k<nn;k++)
    {
        if(m[i]*m[j]*m[k]==n)
        {
            cout<<i<<" "<<j<<" "<<k<<endl;
            ans++;
        }
    }

    cout<<ans;
    return 0;
}
