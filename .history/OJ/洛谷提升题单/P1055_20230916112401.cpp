#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    char s[13]={0};
    gets(s);
    int a[10]={0};
    for(int i=0,k=0;i<13;i++){
        if(s[i]>='0'&&s[i]<='0'){
            a[k]=s[i]-48;
            k++;
        }
    }
    for(int k=0;k<10;k++){
        cout<<a[k]<<" ";
    }
}