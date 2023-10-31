#include<iostream>

using namespace std;

int m,s,c,i,j,k;
int map[205][205]={0};

int main(){
    for(i=0;i<205;i++){
        for(j=0;j<205;j++){
            if(i==j){
                map[i][j]=0;
            }
            else if(j>i){
                map[i][j]=j-i+1;
            }
        }
    }
}