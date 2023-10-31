#include <iostream>

using namespace std;

int m=0,n=0,i=0,j=0,p=0;
int fac(int n){
    int sum=0;
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
    p=fac(m)/(fac(n)fac(m-n));
}