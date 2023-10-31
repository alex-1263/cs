#include<bits/stdc++.h>

using namespace std;

string s1,s2,s3,s4,s5,s6,s7,s8,s9;
int i=0,j=0,k=0;

int main(void){
    

    while(cin>>s1){
        int n=0,ls1=0,b=1;
        ls1=s1.length();
        s2=s1;
        while(1){
            n+=1;
            if(ls1-2<n)
            break;
            s5=s1.substr(0,3);
            if(s5=="],[")
            {
                b+=1;
            }
            s1=s1.substr(1);
        }
        s2=s1;
        
    }

    return 0;
}