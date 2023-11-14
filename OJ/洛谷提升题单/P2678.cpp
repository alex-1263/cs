#include<iostream>
#include<cstdio>

using namespace std;

int map[50005]={0};
int l=0,m=0,n=0,x1=0,x2=0,minmax=0,ll=0;

void change(){
    for(int i=0;i<ll;i++){
        if(map[i]==l){
            
        }
    }

}


int main(){

    cin>>l>>n>>m;
    ll=m;
    for(int i=0;i<n;i++){
        x1=x2;
        cin>>x2;
        map[i]=x2-x1;
        if(i==0){
            minmax=x2;
        }
        if(minmax<x2){
            minmax=x2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<map[i]<<endl;
    }
    for(int i=0;i<m;i++){

    }
}