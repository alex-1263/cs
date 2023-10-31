#include<iostream>
#include<cstdio>

using namespace std;

int a[1001],n=0,m=0,x=0,i=0;

int main(){
    cin>>n>>m;
    for(i=0;i<1001;i++){
        a[i]=0;
    }
    for(i=0;i<m;i++){
        scanf("%d",&x);
        a[x]+=1;
    }
    for(i=0;i<n+1;i++){
        while(a[i]>0){
            a[i]--;
            printf("%d ",i);
        }
    }
}