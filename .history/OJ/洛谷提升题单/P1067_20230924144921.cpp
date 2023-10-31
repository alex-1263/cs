#include<iostream>
#include<cstdio>

using namespace std;

int a[105]={0};


int main(){
    int n=0;
    cin>>n;
    for(int i=0;i<n+1;i++){
        cin>>a[i];
    }
    for(int i=0,j=n;i<n+1;i++,j--){
        if(i==0){
            cout<<a[i]<<"x^"<<j;
        }
        else if(j==0){
            if(a[i]){
                cout<<"+"<<a[i];
            }
            else{
                cout<<a[i];
            }
        }
        else{
            if(a[i]){
                cout<<"+"<<a[i]<<"x^"<<j;
            }
            else{
                cout<<a[i]<<"x^"<<j;
            }            
        }
    }


    return 0;
}