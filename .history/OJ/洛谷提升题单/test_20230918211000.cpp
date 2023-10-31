#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
    string s1="<abnd",s2="a<bdnd",s3="asd<dfs";
    for(int i=0;i<s2.size();i++){
            if(s2[i]=='<'){
                if(i==0){
                    s2=s2.substr(1);
                }
                else if(i==1){
                    s2=s2.substr(2);
                }
                else {
                    s2=s2.substr(3);
                }
            }
	    }
    cout<<s1<<endl<<s2<<endl<<s3;


}