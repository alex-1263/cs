#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s1,s2="..",s3=".",s4="/|",s5,s6,s7,s8,s9,s10,s11,s12,s13;
    while(cin >> s1){
        int i=0,j=0,k=0,l=0,m=0,n=0,ls1=0,ans=0,i1=0;
        ls1=s1.length();
        for(i=0;;i++){
            s4=s1.substr(i,1);
            if(s4=="/"){
                s5=s1.substr(0,i);
                s6=s1.substr(0,i+2);
                n+=s6.length();
                ans++;
                if(s5==s2){
                    if(ans>0)
                    ans--;
                    if(ans>0)
                    ans--;
                }
                if(s5==s3){
                    if(ans>0)
                    ans--;
                }
                if(n==ls1)
                break;
                s1=s1.substr(i+2);
                i=-1;
            }
        }
        cout<<ans;	
    }

    return 0;
}
