#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string s[100005];
int map[100005]={0};

int main(){
    int n=0,m=0,w=0,a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>map[i]>>s[i];
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(map[w]!=a){
            w=(w-b)%n;
            if(w<0)
            w+=n;
        }
        else{
            w=(w+b)%n;
        }
    }
    cout<<s[w];
}