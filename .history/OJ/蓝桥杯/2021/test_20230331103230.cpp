#include<iostream>

using namespace std;

int ans=0,a[10];

int main(){
    for(int i=0;i<10;i++){
       a[i]=2021;
    }
    for(int i=1;;i++){
        int t=i;
        while(t){
            a[t%10]--;
            t/=10;
        }
        for(int j=0;j<10;j++){
            if(a[j]<0){
                cout<<i-1;
                return 0;
            }
        }
    }
}