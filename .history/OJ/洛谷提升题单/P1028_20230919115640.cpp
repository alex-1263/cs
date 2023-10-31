#include<iostream>
#include<cstdio>

using namespace std;

int dg(int x){
    for(int i=1;i<(x/2);i++){
        dg(x)+=dg(i);
    }
    return dg(x);

}


int main(){
    int x=0;
    cin>>x;
    cout<<dg(x);
    return 0;

}