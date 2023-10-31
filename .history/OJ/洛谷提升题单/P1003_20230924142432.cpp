#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int map[10005][10005]={0};

int main(){
int n=0,x1,y1,x2,y2;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>x1>>y1>>x2>>y2;
    for(int j=x1;j<x1+x2;j++){
        for(int k=y1;k<y1+y2;k++){
            map[j][k]=i;
        }
    }
}
cin>>x1>>y1;
cout<<map[x1][y1];


}