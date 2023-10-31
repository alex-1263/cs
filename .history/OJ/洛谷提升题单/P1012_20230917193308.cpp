#include<iostream>
#include<cstdio>

using namespace std;

int n=0,a[25]={0},b[25]={0};
int map[25][11]={0};

int main(){
    cin>>n;
    int maxw=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;;j++){
            map[i][j]=a[i]%10;
            a[i]=a[i]/10;
            if(a[i]<=0)
            break;
        }
    }
}