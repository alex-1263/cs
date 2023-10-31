#include<bits/stdc++.h>
using namespace std;
string str1,str2,str3,str4,str5;

int a[30]={0};
void stra(string str1) {
    int n=0,x=97;
    string z;
    char zz;
    n=str1.length();
    for(int i=0;i<n;i++)
    {
        z=str1.substr(0,1);
        zz=char(z[0]);
        if(zz<=122&&zz>=97)
        a[zz-x]=1;
        str1=str1.substr(1);
    }

}
void findStr(string str1){
    int n=0,x=97;
    string z;
    char zz;
    n=str1.length();
    for(int i=0;i<n;i++){
        z=str1.substr(0,1);
        zz=char(z[0]);
        if(a[zz-x]==1)
        cout<<"Y";
        else
        cout<<"N";
        str1=str1.substr(1);
    }
}


int main(){
    char c;
    c='a';
    printf("%d",c);
    c='z';
    printf("%d",c);
    cin >> str1 >> str2;
    stra(str1);
}