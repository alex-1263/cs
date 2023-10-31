#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    double a=0,b=0,c=0,p=0,s=0;
    cin>>a>>b>>c;
    p=(a+b+c)/2;
    s=p*(p-a)*(p-b)*(p-c);
    s=sqrt(s);
    printf("%.1lf",s);
}