#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

string s1,s2,tmp;
int t;


int main(){
    while(1){
        cin>>tmp;
        if(tmp=="EOF")
        break;
        s1=s1+tmp+" ";

    }
    while(1){
        cin>>tmp;
        if(tmp=="EOF")
        break;
        s2=s2+tmp+" ";

    }
    cin>>t;
    cout<<s1<<endl<<s2<<endl<<t;
    


}