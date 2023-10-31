#include<bits/stdc++.h>

using namespace std;

string s1,s2,s3,s4,s5,s6,s7,s8,s9;
int i=0,j=0,k=0;

int main(void){
    

    while(cin>>s1){
        int n=0,ls1=0,b=1,a=0;
        ls1=s1.length();
        s2=s1;
        while(1){
            n+=1;
            if(ls1-2<n)
            break;
            s5=s2.substr(0,3);
            if(s5=="],[")
            {
                b+=1;
            }
            s2=s2.substr(1);
        }
        s2=s1.substr(2);
        n=0;
         while(1){
            n+=1;
            s5=s2.substr(0,1);
            if(s5=="]")
            break;
            s2=s2.substr(1);
        }
        int map[a+2][b+2];
        for(i=0;i<a+2;i++){
            for(j=0;j<b+2;j++){
                map[i][j]=0;
            }
        }
        s2=s1.substr(2);
        n=0;
        for(i=0;i<b;i++){
            s3=s2.substr(n);
            for(j=0;j<a;j++){
                while(1){

                    if(s5=="1")
                    {
                        map[i][j]=1;
                        s3=s3.substr(2);
                        break;
                    }
                    else if(s5=="0"){
                        map[i][j]=0;
                        s3=s3.substr(2);
                        break;
                    }
                }
            }
            s3=s3.substr(2);
        }
            for(i=0;i<a+2;i++){
            for(j=0;j<b+2;j++){
                cout<<map[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}