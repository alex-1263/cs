#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s1[9]={0},s2[9]={0};
int ss1[8]={0},ss2[8]={0};
int ans=0;

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
    panduan(ss1);
    cout<<ans;
}