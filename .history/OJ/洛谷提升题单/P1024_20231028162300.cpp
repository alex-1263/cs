#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int a=0,b=0,c=0,d=0;
int sum=0,ans[5]={0};

float f(float x){
    return a*x*x*x+b*x*x+c*x+d;
}

int panduan(float x1,float x2){
    if((f(x1)*f(x2))<0&&(x1<x2)){
        cout<<"OK"<<endl;
        if(x1==x2){
            ans[sum]=x1;
            sum++;
        }
        return 1;
    }
    else {
        return 0;
    }
}

void er(float x1,float x2){
    if(panduan(x1,x2)==1){
        cout<<"?";
        er(x1,(x1+x2/2));
        er((x1+x2)/2,x2);
    }
}



int main(){
    cin>>a>>b>>c>>d;
    er(-100,100);
    for(int i=0;i<5;i++){
        cout<<ans[i]<<endl;
    }
}