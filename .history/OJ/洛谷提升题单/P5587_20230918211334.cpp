#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

string s1,s2,tmp;
int t;


int main(){
    while(1){
        cin>>tmp;
        if(tmp=="EOF")
        break;
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

    }
    while(1){
        cin>>tmp;
        if(tmp=="EOF")
        break;
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

    }
    cin>>t;
    cout<<s1<<endl<<s2<<endl<<t;
    


}