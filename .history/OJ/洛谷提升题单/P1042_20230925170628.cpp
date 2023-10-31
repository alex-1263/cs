#include<iostream>
#include<cstdio>

using namespace std;

char s[2505][30]={0};

int main(){
    for(int i=0;i<2505;i++){
        for(int j=0;j<25;j++){
            cin>>s[i][j];
            if(s[i][j]=='E')
            break;
        }
    }


}