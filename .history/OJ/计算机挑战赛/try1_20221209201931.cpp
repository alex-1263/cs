#include<bits/stdc++.h>
using namespace std;
string str1,str2,str3,str4,str5;

char a[30]=" ";
void stra(string str1) {
    int n=0;
    string z;
    n=str1.length();
    for(int i=0;i<n;i++)
    {
        z=str1.substr(0,1);
        if(z=="a")
        cout<<"a";
        str1=str1.substr(1);
    }

}
void findStr(string str1,string str2){
    int n=0;
    n=str1.length();
    cout<<n;
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