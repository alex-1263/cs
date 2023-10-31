/*

*/
#include<iostream>
#include<set>
using namespace std;
int main()
{
    int sum=0,x1=0,x2=0,y1=0,y2=0;
    double k=0,b=0;
    set <pair<double,double> >line;
    for(x1=0;x1<20;x1++)
    {
        for(y1=0;y1<21;y1++)
        {
            for(x2=0;x2<20;x2++)
            {
                for(y2=0;y2<21;y2++)
                {
                   if(x1!=x2&&y1!=y2)
                   { 
                    k=(y2*1.0-y1*1.0)/(x2*1.0-x1*1.0);
                    b=(1.0*x2*y1-1.0*x1*y2)/(x2*1.0-x1*1.0);
                    pair<double,double> newline;
                    newline.first=k;
                    newline.second=b;
                    line.insert(newline);
                   }
                }
            }
        }
    }
     printf("%d",line.size()+20+21);
    return 0;

}
