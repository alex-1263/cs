#include<iostream>
using namespace std;
int main()
{
    int sum=1,x=4;
    for(int i=0;i<19;i++)
    {
        sum+=x;
        x+=4;
    }
    cout<<sum;
    return 0;
}