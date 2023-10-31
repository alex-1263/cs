#include<iostream>
#include<cstdio>

using namespace std;

int n=0,a[25]={0},b[25]={0};
int map[25][11]={0};
string s[20]={"a"},t="a";
int main(){
    cin>>n;
    int maxs=0;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i]>s[j]){
                t=s[j];
                s[j]=s[i];
                s[i]=t;
            }
        }
    }
     for(int i=0;i<n;i++){
       cout<<s[i]<<"\n";
    }
}