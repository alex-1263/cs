#include<iostream>
#include<cstdio>

using namespace std;

char s[2505][30]={0};

int main(){
    int flag=0,a=0,b=0;
    for(int i=0;i<2505;i++){
        for(int j=0;j<25;j++){
            cin>>s[i][j];
            if(s[i][j]=='E')
            {
            flag=1;
            break;
            }
        }
        if(flag)
        break;
    }
    flag=0;       
    for(int i=0;i<2505;i++){
        for(int j=0;j<25;j++){
            if(s[i][j]=='E'){
                flag=1;
                break;
            }
            else if(s[i][j]=='W'){
                a++;
            }
            else if(s[i][j]=='L'){
                b++;
            }
            if(a==11||b==11){
                cout<<a<<":"<<b;
                a=0,b=0;
            }
        }
        if(flag)
        break;
    }

}