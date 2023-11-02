#include<iostream>

using namespace std;

long long dp(long long x){
	if(x<=2){
		return 1;
	}
	else{
		long long ans=(dp(x-1)%100000000+dp(x-2)%100000000)%100000000;
		return ans;
	}
}

int main(){
	

} 