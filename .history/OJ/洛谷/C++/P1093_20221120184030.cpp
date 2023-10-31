#include<bits/stdc++.h>

using namespace std;

int a[305][6];

int main(){
    int n=0,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        a[i][0]=i;
        for(j=1;j<4;j++){
            cin>>a[i][j];
        }
        a[i][4]=a[i][1]+a[i][2]+a[i][3];
    }
    for(int i=1;i<=n;i++){
        for(j=0;j<5;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}