#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

string s1,s2,tmp,tmp1,tmp2;
int t;


int main(){
    while(1){
        cin>>tmp;

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
        s1=s1+tmp+" ";
        if(tmp=="EOF")
        break;        

    }
    while(1){
        cin>>tmp;

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
        s2=s2+tmp+" ";
        if(tmp=="EOF")
        break;
    }
    cin>>t;
    cout<<s1<<endl<<s2<<endl<<t;
    while(1){
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                tmp1=s1.substr(0,i-1);
                cout<<tmp1<<endl;
                if(tmp1=="EOF")
                break;    
                s1=s1.substr(i+1);
                break;
            }
	    }

    }
    cout<<s1<<endl<<s2<<endl<<t;
    


}