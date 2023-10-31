#include<iostream>

using namespace std;

int a=0,b=0,c=0,d=0,k=0,ans=0,i=0,j=0,t=0,za=0,zb=0,zc=0;

int main(){
    cin>>t;
    for(i=0;i<t;i++){
        cin>>a>>b>>c>>d>>k;
        za=a/c;
        if(a%c!=0)
        za++;
        zb=b/d;
        if(b%d!=0)
        zb++;
        zc=zb+za;
        zb=k-za;
        if(zc>k)
        cout<<-1<<endl;
        else
        cout<<za<<" "<<zb;
    }
    return 0;
}