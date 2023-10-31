#include <iostream>

using namespace std;

int n=0,i=0,j=0,k=0,h[10005]={0};
int h1=0,h2=0,h1w=0,h2w=0;
int main(){
    cin >> n ;
    for( i=1;i<=n;i++){
        cin >> h[i] ;
    }
    h1=h[1];
    h1w=1;
    h2=h[2];
    h2w=2;
    if(h2>h1){
        swap(h2,h1);
        swap(h1w,h2w);
    }
    for(i = 1;i<=n;i++){
    if(h[i]<h2){
         cout<< h2w<<" ";
        continue;
    }
    if(i<=2){
        cout<< 0<<" ";
        continue;
    }
        cout <<h2w<<" ";
    if(h[i]>h2)
    {
        h2=h[i];
        h2w=i;
        if(h2>h1)
        {
            swap(h2,h1);
            swap(h2w,h1w);
        }
    }
    }
}