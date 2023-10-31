#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n=0,ans,a1,a2,c1,c2,b1,b2,p1,p2,p3;
    cin>>n>>a1>>a2>>b1>>b2>>c1>>c2;
    p1=n/a1;
    if(n%a1!=0)
    p1++;
    p1=p1*a2;
    p2=n/b1;
    if(n%b1!=0)
    p2++;
    p2=p2*b2;
    p3=n/c1;
    if(n%c1!=0)
    p3++;
    p3=p3*c2;
}