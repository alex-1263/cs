#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s1[9]={0},s2[9]={0};
int ss1[8]={0},ss2[8]={0};
int ans=0;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};


void panduan(int s[]){
    int flag=1;
    for(int i=3,k=4;i>=0;i--,k++){
        if(s[i]!=s[k]){
            flag=0;
            break;
        }
    }
    ans+=flag;
}


int main(){
    gets(s1);
    gets(s2);
    for(int i=0;i<8;i++){
        ss1[i]=s1[i]-'0';
        ss2[i]=s2[i]-'0';
    }
    while(1){
        int month=ss1[4]*10+ss1[5];
        int year=ss1[0]*1000+ss1[1]*100+ss1[2]*10+ss1[3];
        cout<<year <<" "<<month;
        panduan(ss1);
        if(ss1[7]==day[month])
        ss1[7]++;
        break;



    }
    panduan(ss1);
    cout<<ans;
}