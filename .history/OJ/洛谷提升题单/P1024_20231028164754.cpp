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
    if((f(x1)>0&&f(x2<0)&&x1<x2||(f(x1)<0&&f(x2)>0)&&x1<x2)){
        return 1;
    }
    else {
        return 0;
    }
}

void er(float x1,float x2){
    if(panduan(x1,x2)==1){
            float xa=round(x1*100)/100;
            float xc=round(x2*100)/100;
            float xb=(xa+xc)/2;
            xb=round(xb*100)/100;
            if(f(xb)==0){
                ans[sum]=xb;
                sum++;
                
            }
            else{
                cout<<xa<<" "<<xb<<" "<<xc<<endl;
                er(xa,xb);
                er(xb,xc);
                }
    }
}



int main(){
    cin>>a>>b>>c>>d;
    er(0,100);
    for(int i=0;i<5;i++){
        cout<<ans[i]<<endl;
    }
    cout<<f(0);

}