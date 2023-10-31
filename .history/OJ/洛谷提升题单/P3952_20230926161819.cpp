#include<iostream>
#include<cstdio>

using namespace std;

char x[11][105]={0};
string s[11][105]={"0"};
string s1,s2;
int flag_f=0,flag_o=0,flag_n=0,flagx=0,flagxn=0,flag_nmax=0;
int main(){
    int t=0,n[11]={0},flag=1;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n[i];
        cin>>s[i][0];
        s[i][0]=s[i][0].substr(2,s[i][0].length()-3);
        for(int j=1;j<=n[i]+1;j++){
            getline(cin,s[i][j]);
        }
    }
    for(int i=0;i<t;i++){
        int w=0,flag=1;
        flag_f=0,flag_o=0,flag_n=0,flagx=0,flagxn=0,flag_nmax=0;
        for(int j=2;j<=n[i]+1;j++){
            if(s[i][j][0]=='F'){
                flag_f++;
                
                x[i][w]=s[i][j][2];
                for(int k=0;k<w;k++){
                    if(x[i][k]==s[i][j][2]){
                        flag=0;
                        break;
                    }
                    
                }
                s1=s[i][j].substr(4);
                    for(int i=0;i<s1.length()-1;i++){
                        if(s1[i]==' '){
                            s2=s1.substr(i+1);
                            s1=s1.substr(0,i);
                        }
                    }
                    if(s1[0]!='n'&&s2[0]=='n'){
                        if(flag_f>flag_n)
                        flag_n++;
                    }
                    else if(s1[0]='n'){
                        flagx=1;
                        flagxn=flag_n;
                    }else if(s1[0]!='n'&&s2[0]!='n'){
                        int xs1=0,xs2=0;
                        for(int k=0;k<s1.length();k++){
                        xs1=xs1*10;
                        xs1+=int(s1[k]-'0');
                        }
                        for(int k=0;k<s2.length();k++){
                        xs2=xs2*10;
                        xs2+=int(s2[k]-'0');
                        }
                        if(xs2<xs1){
                            flagx=1;
                            flagxn=flag_n;
                            
                        }
                    }
                w++;
            }
            if(s[i][j][0]=='E'){
                flag_f--;
                w--;
            }
            if(flag_f==0){
                if(flag_nmax<flag_n)
                flag_nmax=flag_n;
                flag_n=0;
            }
        }
        if(flag_nmax<flag_n)
            flag_nmax=flag_n;
        if(flag_f!=0){
            flag=0;
        }
        if(flag==1){
            if(s[i][0][0]=='1'){
                if(flagx==0){
                    if(flag_nmax==0)
                    cout<<"Yes"<<endl;
                    else
                    cout<<"No"<<endl;
                    }
                else{
                    if(0==flagxn)
                    cout<<"Yes"<<endl;
                    else
                    cout<<"No"<<endl;
                }
            }else {
                s[i][0]=s[i][0].substr(2);
                int nx=0;
                for(int j=0;j<s[i][0].length();j++){
                    nx=nx*10;
                    nx+=int(s[i][0][j]-'0');
                }
                if(flag_nmax==nx){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
            }
        else{
            cout<<"ERR"<<endl;
        }
    }
}