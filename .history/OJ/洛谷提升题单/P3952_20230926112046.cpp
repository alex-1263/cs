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
        scanf("%d",&n);
        cout<<i<<endl;
        cin>>s[i][0];
        cout<<endl<<n<<endl;
        s[i][0]=s[i][0].substr(2,s[i][0].length()-3);
        cout<<s[0]<<endl;
        for(int j=1;j<=n;j++){
            getline(cin,s[i][j]);
        }
    }
}