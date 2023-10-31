#include <iostream>

using namespace std;

int n=0,i=0,j=0,k=0,h[10005]={0};
int h1=0,h2=0,h1w=0,h2w=0;

int high(int &a){
    j=a;
    int flag=0;
    int x=h[i],res=0;
    h1w=0;
    h2w=0;
    h1=0;
    h2=0;
    for(j=j-1;j>0;j--){
        if(h[j]>x){
            flag++;
            if(h[j]>h1){
                h2=h1;
                h2w=h1w;
                h1=h[j];
                h1w=j;
            }
            else{
            h2=h[j];
            h2w=j; 
            }
            if(flag==2)
            break;
        }
    }
    if(h1!=0&&h2!=0)
    res=h2w;
    else
    res=0;
    return res;
}

int main(){
    cin >> n ;
    for( i=1;i<=n;i++){
        cin >> h[i] ;
    }
    for( i=1;i<=n;i++){
        if(i<=2){
            cout << 0<<" ";
            continue;
        }
        cout << high(i) <<" ";

    }
}