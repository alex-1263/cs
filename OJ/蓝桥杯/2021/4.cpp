#include<iostream>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;
int main()
{
    ll a=2021041820210418;
    ll sum=0;
    ll end1=sqrt(a);
    for(ll i=1;i<=end1;i++)
    {
            if(a%i==0)
            {
                ll aa=a/i;
                ll end2=sqrt(aa);
                for(ll j=1;j<=end2;j++)
                {
                    if(aa%j==0)
                    {
                        ll k=aa/j;
                        if(k>=j&&j>=i)
                        {
                        set<int> s;
                        s.insert(i);
                        s.insert(j);
                        s.insert(k);
                        if(s.size()==1)
                        sum++;
                        else if(s.size()==2)
                        sum+=3;
                        else if(s.size()==3)
                        sum+=6;
                        }
                    }
                }
            }
    }
    cout<<sum;
    
    return 0;
}