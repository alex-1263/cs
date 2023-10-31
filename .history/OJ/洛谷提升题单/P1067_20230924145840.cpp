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
        if(j==n&&n>0){
            if(a[i]==1){
                cout<<"x^"<<j;
            }
            else if(a[i==-1]){
                cout<<"-x^"<<j;
            }
            else{
                if(a[i]!=0){
                cout<<a[i]<<"x^"<<j;                    
                }

            }
        }
        else if(j==1){
            if(a[i]){
                if(a[i]==1){
                    cout<<"+x";
                }
                else{
                    cout<<"+"<<a[i]<<"x";
                }
            }
            else{
                if(a[i]!=0){
                if(a[i]==-1){
                    cout<<"-x";
                }
                else{
                    cout<<a[i]<<"x";
                }                    
                }
            }
        }
        else if(j==0){

        }
    }


    return 0;
}