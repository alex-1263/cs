#include <iostream>

using namespace std;

int n=0,i=0,j=0,k=0,h[10005]={0};
int h1=0,h2=0;
int main(){
    cin >> n ;
    for( i=1;i<=n;i++){
        cin >> h[i] ;
    }
    h1=h[1];
    h2=h[2];
    if(h2>h1){
        swap(h2,h1);
    }
    for(i = 1;i<=n;i++){
    if(h[i]<h2){
         cout<< i<<" ";
        continue;
    }
        cout <<h[0]<<" ";
    h2=h[i];
    if(h2>h1){
        swap(h2,h1);
    }
    }
}