#include<bits/stdc++.h>

using namespace std;

string s1,s2,s3,s4,s5,s6,s7,s8,s9;
int i=0,j=0,k=0;

int main(void){
    

    while(cin>>s1){
        int n=0,ls1=0,b=1,a=0,sum1=0,sum2=0,z=0,x=0,y=0,ans=0;
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
        a=n/2;
        int aa[a+2][b+2];
        s3=s1.substr(2);
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                    s5=s3.substr(0,1);
                    if(s5=="1")
                    {
                       aa[i][j]=1;
                    }
                    if(s5=="0"){
                        aa[i][j]=0;
                    }
                    s3=s3.substr(2);
            }
            if(s3.length()<=3)
            {break;}
            s3=s3.substr(2);
        }
            for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                cout<<aa[i][j];
            }
            cout<<endl;
        }
        for(i=0;i<a;i++){
            sum1=0;
            for(j=0;j<b;j++){
                if(aa[i][j]==1){
                    y=j;
                    sum1+=1;
                    if(sum1>1)
                    break;
                }
                if(sum1==1){
                    z=i;
                    i=y;
                    for(k=i;k<a;k++){
                        if(k==1){
                            sum2+=1;
                        }
                        if(sum2>1)
                        break;
                    }
                }
                if(sum1==1)
                i=z;
                if(sum1==1&&sum2==1)
                ans++;
            }
        }
    }

    return 0;
}