#include<iostream>
#include<cstdio>

using namespace std;

string s1="",s2="",ss="0";
int t;

int main(){
    while(1){
        cin>>ss;
        if(ss=="EOF")
        break;
        s1+=ss;
    }
    while(1){
        cin>>ss;
        if(ss=="EOF")
        break;
        s2+=ss;
    }
    cin>>t;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<t;


}