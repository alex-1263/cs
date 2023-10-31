#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

long long map[1005][1005]={0},nm[1005][1005]={0},n=0,m=0,ans=0,xx=0,x=0,y=0,r=0;
void boom(long long x,long long y,int r){
	for(int i=x-r;i<=x+r;i++)
	for(int j=y-r;j<=y+r;j++){
		xx=(i-x)*(i-x)+(j-y)*(j-y);
		if(xx<r*r){
			ans+=nm[i][j];
			nm[i][j]=0;
			boom(i,j,map[i][j]);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x>>y>>r;
		map[x][y]=r;
		nm[x][y]++;
	}
	for(int i=0;i<m;i++){
		cin>>x>>y>>r;
        boom(x,y,r);
	}
	cout<<ans<<endl;
	return 0;
}


