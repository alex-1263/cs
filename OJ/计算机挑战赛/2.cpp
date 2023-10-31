#include <iostream>

using namespace std;

long long m=0,n=0,i=0,j=0,p=0,x=1;
long long fac(int n){
    long long sum=0;
    if(n==0||n==1)
    {
        sum=1;
    }
    if(n>=2)
    {
        sum=n*fac(n-1);
    }
    return sum;
}

int main(){
    cin >> m>>n;
    if(n>m)
    swap(m,n);
    for(i=m;i>n;i--){
        x*=i;
    }
    p=x/fac(m-n);
    cout << p;
}