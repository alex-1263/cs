#include<iostream>
using namespace std;
int main()
{
    int a[10]={0},q=0,b=0,s=0,g=0;
    for(int i=1;i<2021;i++)
    {
        if(i<10)
        a[i]++;
        else if(i<100)
        {
            s=i/10;
            g=i%10;
            a[s]++;
            a[g]++;
        }
        else if(i<1000)
        {
            b=i/100;
            s=(i%100)/10;
            g=i%10;
            a[s]++;
            a[g]++;
            a[b]++;
        }
        else 
        {
            q=i/1000;
            b=(i%1000)/100;
            s=(i%100)/10;
            g=(i%10);
            a[q]++;
            a[b]++;
            a[s]++;
            a[g]++;
        }
    }
    cout <<a[2];
    return 0;
}