#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

long long mapr[50005]={0},mapx[50005]={0},mapy[50005]={0},nm[50005][50005]={0},n=0,m=0,ans=0,xx=0,x=0,y=0,r=0;

void bigboom(long long i){
    for(int j=0;j<n;j++){
        if(nm[i][j]){
            ans+=nm[j][j];
            nm[i][j]=0;
            nm[j][i]=0;
            bigboom(j);
        }
    }
}

void boom(long long x,long long y,long long r){
    for(int i=0;i<n;i++){
        r=max(r,mapr[i]);
        if(r*r>=(x-mapx[i])*(x-mapx[i])+(y-mapy[i])*(y-mapy[i])){
            ans+=nm[i][i];
            nm[i][i]=0;
            bigboom(i);
        }

    }
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x>>y>>r;
        mapr[i]=max(r,mapr[i]);
        mapx[i]=x;
        mapy[i]=y;
	}
    for(int i=0;i<n;i++){
        nm[i][i]=1;
        for(int j=i;j<m;j++){
            if(mapr[i]*mapr[i]>=(mapx[i]-mapx[j])*(mapx[i]-mapx[j])+(mapy[i]-mapy[j])*(mapy[i]-mapy[j])){
                nm[i][j]++;
                nm[j][i]++;
            }
        }
    }
    
	for(int i=0;i<m;i++){
		cin>>x>>y>>r;
        boom(x,y,r);
	}
	cout<<ans<<endl;
	return 0;
}


