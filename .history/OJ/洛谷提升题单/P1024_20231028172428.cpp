#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

float a=0,b=0,c=0,d=0;
int sum=0;
float ans[5]={0};

float f(float x){
    float ans=a*x*x*x+b*x*x+c*x+d;
    ans=round(ans*100)/100;
    return ans;
}

int panduan(float x1,float x2){
    if((f(x1)>0&&f(x2)<0)||(f(x1)<0&&f(x2)>0)){
        return 1;
    }
    else {
        return 0;
    }
}

void er(float x1,float x2){
    if(panduan(x1,x2)){
            float xa=round(x1*100)/100;
            float xc=round(x2*100)/100;
            float xb=(xa+xc)/2;
            xb=round(xb*100)/100;
            if(x2-x1<=0.01){
                if(f(xb)==0){
                    ans[sum]=xb;
                    sum++;
                }
                else if(f(xa)==0){
                    ans[sum]=xa;
                    sum++;
                }
                else if(f(xc)==0){
                    ans[sum]=xc;
                    sum++;
                } 
            }
            else{
                cout<<xa<<' '<<xb<<' '<<xc<<endl;
                er(xa,xb);
                er(xb,xc);
                }
    }else if(x2-x1>=1){
            float xa=round(x1*100)/100;
            float xc=round(x2*100)/100;
            float xb=(xa+xc)/2;
            er(xa,xb);
            er(xb,xc);

    }
}



int main(){
    cin>>a>>b>>c>>d;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    cout<<f(4);
    er(-100,100);
    sort(ans,ans+3);
    for(int i=0;i<3;i++){
        if(i!=0){
            cout<<" ";
        }        
        printf("%.2f",ans[i]);
    }
}