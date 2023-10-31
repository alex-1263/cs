#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

long long ans[30][30][30]={0};

long long w(long long a,long long b,long long c){

    if(a<=0||b<=0||c<=0){
        return 1;
    }
    else if(a>20||b>20||c>20){
        return  w(20,20,20);
    }
    else if(a<b&&b<c){
        if(ans[a][b][c-1]==0){
            ans[a][b][c-1]=w(a,b,c-1);
        }
        if(ans[a][b-1][c-1]==0){
            ans[a][b-1][c-1]=w(a,b-1,c-1);
        }
        if(ans[a][b-1][c]==0){
            ans[a][b-1][c]=w(a,b-1,c);
        }
        return ans[a][b][c-1]+ans[a][b-1][c-1]-ans[a][b-1][c];
    }
    else{
        if(ans[a-1][b][c]==0){
            ans[a-1][b][c]=w(a-1,b,c);
        }
        if(ans[a-1][b-1][c]==0){
            ans[a-1][b-1][c]=w(a-1,b-1,c);
        }
        if(ans[a-1][b][c-1]==0){
            ans[a-1][b][c-1]=w(a-1,b,c-1);
        }
        if(ans[a-1][b-1][c-1]==0){
            ans[a-1][b-1][c-1]=w(a-1,b-1,c-1);
        }
        return ans[a-1][b][c]+ans[a-1][b-1][c]+ans[a-1][b][c-1]-ans[a-1][b-1][c-1];
    }
}


int main(){
    long long a,b,c;    
    while(1){
    cin>>a>>b>>c;
    if(a==-1&&b==-1&&c==-1){
        break;
    }    
    printf("w(%lld, %lld, %lld) = ",a,b,c);
    cout<<w(a,b,c)<<endl; 

    }


}