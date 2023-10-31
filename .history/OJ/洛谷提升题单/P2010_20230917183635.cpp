#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char s1[9]={0},s2[9]={0};
int ss1[8]={0},ss2[8]={0};
int ans=0;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};


void panduan(int s[]){
    int flag=1;
    for(int i=3,k=4;i>=0;i--,k++){
        if(s[i]!=s[k]){
            flag=0;
            break;
        }
    }
    ans+=flag;
}


int main(){
    gets(s1);
    gets(s2);
    int dayy,month,year,flag11;
    for(int i=0;i<8;i++){
        ss1[i]=s1[i]-'0';
        ss2[i]=s2[i]-'0';
    }
    while(1){
        flag11=1;
        month=ss1[4]*10+ss1[5];
        year=ss1[0]*1000+ss1[1]*100+ss1[2]*10+ss1[3];
        dayy=ss1[6]*10+ss1[7];
        if(year%4==0&&year%100!=0){
            day[2]=29;
        }
        else if(year%400==0){
            day[2]=29;
        }
        else{
            day[2]=28;
        }
        panduan(ss1);
        for(int i=0;i<9;i++){
            if(ss1[i]!=ss2[i])
            flag11=0;
        }
        if(flag11)
        break;
        if(dayy==day[month]){
            if(month==12){
                year++;
                ss1[0]=year/1000;
                ss1[1]=(year/100)%10;
                ss1[2]=(year/10)%10;
                ss1[3]=year%10;
            }
            dayy=0;
            month++;
            if(month>12)
            month=1;
        }
            dayy++;
            ss1[4]=month/10;
            ss1[5]=month%10;
            ss1[6]=dayy/10;
            ss1[7]=dayy%10;

    }
        cout<<ans;

}