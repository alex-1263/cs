#include<iostream>
#include<cstdio>

using namespace std;

int ansa=0,ansb=0,a[205]={0},b[205]={0};

void caiquan(int x,int y){
    if(x!=y){
        if(x==0){
            if(y==1||y==4){
                ansb++;
            }
            else {
                ansa++;
            }
        }
        else if(x==1){
            if(y==0||y==3){
                ansa++;
            }
            else{
                ansb++;
            }
        }
        else if(x==2){
            if(y==1||y==4){
                ansa++;
            }
            else{
                ansb++;
            }
        }
        else if(x==3){
            if(y==0||y==1){
                ansb++;
            }
            else{
                ansa++;
            }
        }
        else if(x==4){
            if(y==0||y==1){
                ansa++;
            }
            else{
                ansb++;
            }
        }
    }
}

int main(){
    int n=0,na=0,nb=0;
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++){
        cin>>a[i];
    }
    for(int i=0;i<nb;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        caiquan(a[i%na],b[i%nb]);
    }

}