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


}