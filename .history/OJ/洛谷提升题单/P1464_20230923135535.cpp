#include<iostream>
#include<cstdio>
#include<cstdio>
using namespace std;


long long w(long long a,long long b,long long c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }
    else if(a>20||b>20||c>20){
        return  w(20,20,20);
    }
    else if((a==b)&&b==c){
        return pow(2,a);
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
    while(1){
    cin>>a;
    cout<<w(a,a,a);
    cout<<endl<<"end";    
    if(a==-2){
        break;
    }
    }


}