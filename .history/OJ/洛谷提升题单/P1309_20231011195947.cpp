#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct xs{
    int id,grade,power;
    xs();
    xs(int id,int grade,int power)  : id(id) ,grade(grade), power(power) {};
};

vector<xs> list1;

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
    cin>>n>>r>>q;
    for(int i=0;i<n*2;i++){
        cin>>list1[i].grade;
        list1[i].id=i;
    }
    for(int i=0;i<n*2;i++){
        cin>>list1[i].power;
    }
    sort(list1.begin(),list1.end(),cmp);
    for(int i=0;i<n*2;i++){
        cout<<list1[i].id<<" "<<list1[i].grade<<" "<<list1[i].power<<endl;
    }


}
