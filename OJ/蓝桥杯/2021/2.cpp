#include<iostream>
using namespace std;
int main()
{
    int i=0,flag=0,g=0,s=0,b=0,q=0,sum=0;
    int pai[10]={0};
    for(int i=0;i<10;i++)
    {
        pai [i]=2021;
    }
    for(int i=1;;i++)
    {
        if(i<10)
        {
            pai[i]--;
        }
        else if(i<100)
        {
            s=i/10;
            g=i%10;
            pai[s]--;
            pai[g]--;
        }
        else if(i<1000)
        {
            b=i/100;
            s=(i%100)/10;
            g=i%10;
            pai[b]--;
            pai[s]--;
            pai[g]--;
        }
        else
        {
            q=i/1000;
            b=(i%1000)/100;
            s=(i%100)/10;
            g=i%10;
            pai[q]--;
            pai[b]--;
            pai[s]--;
            pai[g]--;
        }
        for(int j=0;j<10;j++)
        {
            if(pai[j]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            sum=i;
            break;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(pai[i]<0)
        {
            sum--;
            break;
        }
    }
    cout<<sum<<endl;

    /*
        0   1  2  3  4  5  6  7  8  9
        10 11 12 13 14 15 16 17 18 19
        20 21 22 23 24 25 26 27 28 29 
        30 31 32 33 34 35 36 37 38 39 
    */
}