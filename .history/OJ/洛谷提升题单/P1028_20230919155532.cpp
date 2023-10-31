#include<iostream>
#include<cstdio>

using namespace std;


int sum[1005]={0};



int main(){
    sum[0]=0;
    sum[1]=1;
    sum[2]=2;
    sum[3]=2;
    sum[4]=4;
    int x=0;
    cin>>x;
    if(x>4){
        for(int i=5;i<=x;i++){
            if(i%2==0){
                sum[i]=sum[i-1]+sum[i/2];
            }
            else{
                sum[i]=sum[i-1];
            }
        }
    }
    cout<<sum[x];
    return 0;

}