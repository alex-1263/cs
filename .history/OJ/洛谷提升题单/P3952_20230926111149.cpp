#include<iostream>
#include<cstdio>

using namespace std;

char x[11][105]={0};
string s[105]={"0"};
int flag_f=0,flag_o=0;
int main(){
    int t=0,n=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<endl<<n;
        cin>>s[0];
        s[0]=s[0].substr(2,s[0].length());
        cout<<s[0]<<endl;
        for(int j=1;j<=n;j++){
            getline(s[j]);
        }
    }
}