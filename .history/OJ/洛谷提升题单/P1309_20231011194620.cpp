#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct xs{
    int id,grade,power;

};

struct xs list1[100000005]
{
    /* data */
};

bool cmp(xs s1,xs s2){
    if(s1.grade!=s2.grade){
        return s1.grade>s2.grade;
    }
    else{
        return s1.id<s2.id;
    }
}



int main(){
    int n=0,r=0,q=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list1[i].grade;
        list1[i].id=i;
    }
    for(int i=0;i<n;i++){
        cin>>list1[i].power;
    }
//sort(list1[0],list1[n],cmp);
    for(int i=0;i<n;i++){
        cout<<list1[i].id<<" "<<list1[i].grade<<" "<<list1[i].power<<endl;
    }


}