#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int n=0,m=0;
long long ans=1,j=2;


long long js(long long jj,int n1,int m1){
    if(jj*2<=m1&&(jj-1)*pow(2,n1)>=m1)
    return js(jj*2,n1-1,m1)+js(jj-1,n1,m1-1);
    if(jj*2>m1)
    return js(jj-1,n1,m1-1);
    if((jj-1)*pow(2,n1)<m1)
    return js(jj*2,n1-1,m1);
}

int main(){
    cin>>n>>m;

}