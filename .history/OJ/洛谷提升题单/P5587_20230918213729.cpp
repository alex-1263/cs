#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

string s1,s2,tmp,tmp1,tmp2;
int t,ans=0;


int main(){
    while(1){
        getline(cin,tmp);

	    for(int i=0;i<tmp.size();i++){
            if(tmp[i]=='<'){
                if(i==0){
                    tmp=tmp.substr(1);
                    i--;
                }
                else if(i==1){
                    tmp=tmp.substr(2);
                    i-=2;
                }
                else {
                    tmp=tmp.substr(0,i-2)+tmp.substr(i+1);
                    i-=2;
                }

            }
	    }
        s1=s1+tmp+"\\";
        if(tmp=="EOF")
        break;        

    }
    while(1){
        getline(cin,tmp);

	    for(int i=0;i<tmp.size();i++){
            if(tmp[i]=='<'){
                if(i==0){
                    tmp=tmp.substr(1);
                    i--;
                }
                else if(i==1){
                    tmp=tmp.substr(2);
                    i-=2;
                }
                else {
                    tmp=tmp.substr(0,i-2)+tmp.substr(i+1);
                    i-=2;
                }

            }
	    }        
        s2=s2+tmp+"\\";
        if(tmp=="EOF")
        break;
    }
    cin>>t;
    cout<<s1<<endl<<s2<<endl<<t<<endl;
    while(1){
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='\\'){
                tmp1=s1.substr(0,i);
                cout<<tmp1<<endl;
                if(tmp1=="EOF")
                break;    
                s1=s1.substr(i+1);
                break;
            }
	    }
        for(int i=0;i<s2.size();i++){
            if(s2[i]=='\\'){
                tmp2=s2.substr(0,i);
                cout<<tmp2<<endl;
                if(tmp2=="EOF")
                break;    
                s2=s2.substr(i+1);
                break;
            }
	    }
                if(tmp1=="EOF")
                break;  
                if(tmp2=="EOF")
                break;
        for(int i=0;i<min(tmp1.size(),tmp2.size());i++){
            if(tmp1[i]==tmp2[i]){
                ans++;
            }
	    }
    }
    float kmp=0;
    kmp=(ans*1.0/t*1.0)*60.0;
    float x=0;
    x=kmp-int(kmp);
    if(x>=0.5);
    cout<<kmp;
}