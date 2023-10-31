#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
    string s1="<abnd",s2="a<bdnd",s3="asd<dfs";
    for(int i=0;i<s1.size();i++){
            if(s1[i]=='<'){
                if(i==0){
                    s1=s1.substr(0);
                }
                else if(i==1){
                    s1=s1.substr(2);
                }
                else {
                    s1=s1.substr(3);
                }
            }
	    }
    cout<<s1<<endl<<s2<<endl<<s3;


}