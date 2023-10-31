#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int cmp0 (int x, int y){
	return x > y;
}
int x[100005],y[2][100005],z[2][100005];
int n,m,a=100005,b=0,flag=0,j=1,i;
int main(){
	for(i = 1; i <= 100000; i++)x[i] = i;
	scanf("%d %d",&n,&m);
	for(i = 1; i <= m; i++){
		scanf("%d %d",&y[0][i],&y[1][i]);
		if(i=1){
			z[0][j]=y[0][i];
			z[1][j]=y[1][i];
		}
		if(i>1){
			if(flag = 0){
				if(y[0][i]==y[0][i-1])
				flag = 1;
			}
			else{
				if(y[0][i]==y[0][i-1]){
					if(y[0][i]==1){
						a = min(a,y[0][i]);
					}
					else{
						b = max(b,y[0][i]);
					}
				}
				else{
					flag = 0;
					z[0][j]=y[0][i-1];
					if(z[0][j]){
						z[1][j]=a;
					}
					else{
						z[1][j]=b;
					}
					j++;
					a=100005;
					b=0;
				}
			}
		}
	}
	if(flag = 1){
		z[0][j]=y[0][i-1];
					if(z[0][j]){
						z[1][j]=a;
					}
					else{
						z[1][j]=b;
					}
					j++;
	}
	for(i = 1; i <= j; i++){
		if(z[0][i]){
			sort(x+z[1][i],x+n+1);
		}
		else{
			sort(x+1,x+z[1][i]+1,cmp0);
		}
	}
	for(i = 1; i <= n; i++){
		printf("%d ",x[i]);
	}
}
