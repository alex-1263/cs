#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s1[9]={0},s2[9]={0};
int ans=0;

void panduan(char s[]){
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
    panduan(s1);
    cout<<ans;
}