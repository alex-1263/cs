#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    char s[10]={0};
    int ans=0;
    gets(s);
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if('0'<=s[i]<='9')
        ans++;
        if('a'<=s[i]<='z')
        ans++;
        if('A'<=s[i]<='Z')
        ans++;
    }

}