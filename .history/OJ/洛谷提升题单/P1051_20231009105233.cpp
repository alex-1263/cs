#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
    int n=0,pjf,bjf,lw,sum=0,max=0,ans=0;
    char flag1,flag2;
    string name,maxname;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name>>pjf>>bjf>>flag1>>flag2>>lw;
        ans=0;
        if(pjf>80&&lw>=1)
        ans+=8000;
        if(pjf>85&&bjf>80)
        ans+=4000;
        if(pjf>90)
        ans+=2000;
        if(pjf>85&&flag2=='Y')
        ans+=1000;
        if(bjf>80&&flag1=='Y')
        ans+=850;
        if(ans>max){
            max=ans;
            maxname=name;
        }
        sum+=ans;
    }
    cout<<maxname<<endl<<max<<endl<<sum;
}