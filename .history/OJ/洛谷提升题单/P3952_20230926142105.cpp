#include<iostream>
#include<cstdio>

using namespace std;

char x[11][105]={0};
string s[11][105]={"0"};
string s1,s2;
int flag_f=0,flag_o=0,flag_n=0;
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
        int w=0;
        for(int j=2;j<=n+1;j++){
            
            if(s[i][j][0]=='F'){
                flag_f++;
                
                x[i][w]=s[i][j][2];
                for(int k=0;k<w;k++){
                    if(x[i][k]==s[i][j][2]){
                        cout<<"ERR"<<endl;
                        break;
                    }
                    s1=s[i][j].substr(4);
                    for(int i=0;i<s1.length()-1;i++){
                        if(s1[i]==' '){
                            s2=s1.substr(i+1);
                            s1=s1.substr(0,i);
                        }
                    }
                    if(s1[0]=='n'&&s2[0]!='n'){
                        flag_o=1;
                    }
                    else if(s1[0]!='n'&&s2[0]=='n'){
                        flag_n++;
                    }
                }
                w++;
            }
            else if(s[i][j][0]=='E'){
                flag_f--;
                w--;
                x[i][w]=0;
            }
        }
        if(s[i][0][0]==1&&flag_n==0){
            cout<<"Yes"<<endl;
        }
        cout<<flag_f<<endl;

    }
}