#include<iostream>
#include<cstdio>

using namespace std;
int main(){
    int i=0,j=0,x=0;
    char a;
    cin>>a;
    for(i=1;i<4;i++){
        x=3-i;
        for(j=0;j<x;j++){
            printf(" ");
        }
        for(j=0;j<i*2-1;j++){
            cout<<a;
        }
        printf("\n");
    }
}