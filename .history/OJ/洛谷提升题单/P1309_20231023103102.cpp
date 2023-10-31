#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct xs{
    int id,grade,power;
}list1 [100000005];



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
        list1[i].id=i+1;
    }
    for(int i=0;i<n*2;i++){
        cin>>list1[i].power;
    }
    sort(list1,list1+2*n,cmp);
    for(int  i=0;i<r;i++){
        for(int j=0;j<n*2;j+=2){
            if(list1[j].power>list1[j+1].power)
            list1[j].grade++;
            else if(list1[j].power<list1[j+1].power)
            list1[j+1].grade++;

        }
        sort(list1,list1+2*n,cmp);            
    }
    
    cout<<list1[q-1].id;


}
