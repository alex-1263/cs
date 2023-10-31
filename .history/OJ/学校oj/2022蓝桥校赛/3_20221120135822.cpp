#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[5]={0,0,0,0,0};
    while(cin>>a[0]){
        for(int i=1;i<5;i++){
            cin>>a[i];
        }
        for(int i=0;i<5;i++){
            cout<<a[i]<<endl;
        }
    }

}

