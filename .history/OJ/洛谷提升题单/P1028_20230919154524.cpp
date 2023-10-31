#include<iostream>
#include<cstdio>

using namespace std;


int sum[1005]={0};



int main(){
    sum[0]=0;
    sum[1]=1;
    sum[2]=1;
    sum[3]=2;
    sum[4]=2;
    int x=0;
    cin>>x;
    if(x>4){
        for(int i=5;i<=x;i++){
            for(int j=0;j<(i/2);j++){
                sum[i]+=sum[j];
            }
        }
    }
    cout<<sum[x];
    return 0;

}