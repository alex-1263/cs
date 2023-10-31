#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int h=0,r=0,ans;
    double pie=3.141592653,v=0,x=0;
    cin>>h>>r;
    v=pie*r*r*h;
    x=20000/v;
    ans=int(x)+1;
    cout<<ans;
}