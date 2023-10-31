#include<iostream>
#include<algorithm>
using namespace std;
int a[11111][11111],x,n,sum=0,flag=0;
int main(){
	for(int i = 0; i < 11111; i++){
		x=1;
		for(int j = i; j < 11111; j++){
			a[i][j]=x;
			x+=i;
		}
	}
	cin>>n;
	for(int j = 0; j < 11111; j++){
		for(int i = 0; i <= j; i++){
			sum++;
			if(a[i][j]==n){
				printf("%d",sum);
				flag=1;
				break;
			}
		}
					if(flag==1)
			break;
	}
}
