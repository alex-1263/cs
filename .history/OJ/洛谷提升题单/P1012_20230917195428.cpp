#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int n=0,a[25]={0},b[25]={0};
int map[25][11]={0};
char s[25][11]={0};
string s[21]={0};
int main(){
    cin>>n;
    int maxs=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;;j++){
            s[i][j]=a[i]%10+'0';
            a[i]=a[i]/10;
            if(a[i]<=0)
            break;
        }
    }
    
}