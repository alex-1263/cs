#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    char s[13]={0};
    gets(s);
    int a[10]={0},ans=0;
    for(int i=0,k=0;i<13;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-48;
            k++;
        }
    }
    for(int k=0;k<9;k++){
        ans+=a[k]*(k+1);
    }
    ans=ans%11;
    if(ans==a[10]){
        cout<<"Right";
    }
    else{
        s[12]=ans+48;
        cout<<s;
    }
}