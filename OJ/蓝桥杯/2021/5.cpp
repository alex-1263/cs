#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define   INF   999999999
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int M[2022][2022];
int main()
{
    for(int i=1;i<=2021;i++)
    {
        for(int j=1;j<=2021;j++)
        {
            if(i==j)M[i][j]=M[j][i]=0;
            else if(abs(i-j)>21)M[i][j]=M[j][i]=INF;
            else M[i][j]=M[j][i]=i*j/gcd(i,j);
        }
    }
    for(int i=1;i<=2021;i++)
    {
        for(int j=1;j<=2021;j++)
        {
            for(int k=1;k<=j;k++)
            {
                if(M[i][k]!=INF&&M[k][j]!=INF&&(M[i][j]>M[i][k]+M[k][j]))
                {
                    M[i][j]=M[j][i]=M[i][k]+M[k][j];
                }
            
        }
    }
    }
    cout<<M[1][2021];
    return 0;
}
