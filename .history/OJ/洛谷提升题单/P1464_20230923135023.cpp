#include<iostream>
#include<cstdio>

using namespace std;


long long w(long long a,long long b,long long c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }
    else if(a==10,b==10,c==10){
        return 1024;
    }
    else if(a==11,b==11,c==11){
        return 12288;
    }
    else if(a>20||b>20||c>20){
        return  w(20,20,20);
    }
    else if(a<b&&b<c){
        return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }
    else{
        return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
}


int main(){
    int a;
    cin>>a;
    cout<<w(12,12,12);
    cout<<endl<<"end";

}