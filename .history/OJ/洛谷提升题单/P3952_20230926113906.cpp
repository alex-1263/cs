#include<iostream>
#include<cstdio>

using namespace std;

char x[11][105]={0};
string s[11][105]={"0"};
int flag_f=0,flag_o=0;
int main(){
    int t=0,n=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>s[i][0];
        s[i][0]=s[i][0].substr(2,s[i][0].length()-3);
        for(int j=1;j<=n+1;j++){
            getline(cin,s[i][j]);
        }
    }
    for(int i=0;i<t;i++){
        for(int j=2;j<=n+1;j++){
            if(s[i][j][0]=='F'){
                flag_f++;
            }
            else (s[i][j][0]=='E'){
                flag_f--;
            }
        }
        cout<<flag_f<<endl;
    }
}