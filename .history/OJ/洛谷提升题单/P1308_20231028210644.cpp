#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char s1[1000005]={0},s2[15]={0};

int main(){
    gets(s2);
    gets(s1);
    char a=' ';
    int n2=strlen(s2);
    int n1=strlen(s1);
    int ans=0,w=0,flagw=0;
    for(int i=0;i<n1+1;i++){
        if(s1[i]>=65&&s1[i]<=90)
        s1[i]+=32;
    }
    for(int i=0;i<n2+1;i++){
        if(s2[i]>=65&&s2[i]<=90)
        s2[i]+=32;        
    }
    for(int i=0;i<n1;i++){
        if(s1[i]==s2[0]){
            int w1=i;
            if(s1[i-1]==32||i==0){
                int flag=1;
                for(int k=i;k<n2+i;k++){
                    if(s1[k]!=s2[k-i])
                    flag=0;
                }
                if(flag==1&&s1[i+n2]==32){
                    ans++;
                    if(flagw==0){
                        w=w1;
                        flagw=1;
                    }
                }
            }
        }
    }
    if(ans!=0)
    cout<<ans<<" "<<w;
    else
    cout<<-1;


} 