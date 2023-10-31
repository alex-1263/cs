#include<iostream>
#include<algorithm>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int dp[105][100005];
int ans;
int m[105]={0}, n = 0;
int main(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>m[i];
	}
	for(int i = 0; i< 105; i++){
		dp[i][0]=1;
	}
	sort(m+1,m+n+1,cmp);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 100005; j++){
			if(dp[i-1][j]){
				dp[i][j]=1;
				dp[i][j+m[i]]=1;
				if((j-m[i])>0){
					dp[i][j-m[i]]=1;
				}
			}
		}
	}
	for(int i = 1;i < 100005; i++){
		if(dp[n][i])
		ans++;
	}
	cout<<ans;
    return 0;
}
