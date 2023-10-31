#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll days =24*60*60*1000;
    ll n=0;
    ll hh=0,mm=0,ss=0;
    cin>>n;
    ss=n%days;
    ss/=1000;
    hh=ss/3600;
    mm=(ss%3600)/60;
    ss%=60;
    printf("%02lld:%02lld:%02lld",hh,mm,ss);
    return 0;
}
