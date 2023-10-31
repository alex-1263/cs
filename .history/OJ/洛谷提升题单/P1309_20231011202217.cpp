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
        for(i=0;i<n*2;i+=2){
            if(list1[i].power>list1[i+1].power)
            list1[i].grade++;
            else if(list1[i].power<list1[i+1].power)
            list1[i+1].grade++;
            for(int i=0;i<n*2;i++){
                cout<<list1[i].id<<" "<<list1[i].grade<<" "<<list1[i].power<<endl;
            }
        }
        sort(list1,list1+2*n,cmp);
    }
    
    cout<<list1[q-1].id;


}
