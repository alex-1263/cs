#include<iostream>
#include<cstdio>

using namespace std;

int n=0;
string s[25]={"a"},t="a";
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i]>=s[j]){
                t=s[j];
                s[j]=s[i];
                s[i]=t;
            }
        }
    }
     for(int i=0;i<n;i++){
       cout<<s[i];
    }
}