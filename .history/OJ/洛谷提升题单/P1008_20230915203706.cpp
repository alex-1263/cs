#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int a=123,b,c;
int panduan(int a,int b,int c){
    int a1=a/100,a2=a%100,a3=a%10;
    a2=a2/10;
    int b1=b/100,b2=b%100,b3=b%10;
    b2=b2/10;
    int c1=c/100,c2=c%100,c3=c%10;
    c2=c2/10;
    int flag[11]={};
    flag[a1]++;
    flag[a2]++;
    flag[a3]++;
    flag[b1]++;
    flag[b2]++;
    flag[b3]++;
    flag[c1]++;
    flag[c2]++;
    flag[c3]++;
    int flag1=1;
    if(a==125){
        cout<<a<<' '<<b<<' '<<c;
    }
    for(int i=1;i<11;i++){
        if(flag[i]!=1){
            flag1=0;
            break;
        }
    }
    return flag1;
}
int main(){
    int flag=0;
    for(a=123;a<335;a++){
        b=2*a;
        c=3*a;
        if(panduan(a,b,c)){
            printf("%d %d %d\n",a,b,c);
        }
    }
}

