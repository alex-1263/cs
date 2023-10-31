#include<iostream>

using namespace std;

int a=0,b=0,t=0,n=0,i=0,j=0,k=0,sum=0,ans=0;
int x[100005]={0};

int js(int a,int b)
{
    int flag = 0;
    while(1)
    {
        b=b*b;
        if(a==b){
            flag = a;
            break;
        }
        else if(a<b){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> x[i];
    }
    for(i=1;i<=n;i++){
                sum=0,ans=0;
        for(j=0;j<i;j++){
            k=js(x[j],x[i]);
            if(k!=0){
            sum++;
            ans+=k;
            }
        }
        cout<<sum<<" "<<ans<<endl;
    }
    return 0;
}