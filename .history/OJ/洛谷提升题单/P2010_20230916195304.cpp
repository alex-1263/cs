#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s1[9]={0},s2[9]={0};


int panduan(char s[]){
    char s3[9]={0};
    for(int i=8,k=0;i>=0;i--,k++){
        s3[i]=s[k];
    }
    cout<<strcmp(s,s3);
    return 0;
}


int main(){
    gets(s1);
    gets(s2);
    panduan(s1);

}