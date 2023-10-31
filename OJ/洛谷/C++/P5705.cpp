#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    int s=0,v=0,t=0,h=0;
    cin>>s>>v;
    if(s%v==0)
    t=s/v;
    else
    t=s/v+1;
    t+=10;
    while(t>=60){
        t=t-60;
        h++;
    }
    if(h>8)
    h=24-h+7;
    else
    h=7-h;
    t=60-t;
    printf("%02d:%02d",h,t);
}