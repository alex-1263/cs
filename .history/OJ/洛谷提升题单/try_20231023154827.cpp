#include<stdio.h>
int main(){
	int i,k;
	double sum=1;
	scanf("%d",&k);
	while(true){
		for(i=2;i<=1000;i++){
			sum=sum+1.0/i; 
			if(sum>k){
				break;
			}
		}
		printf("%d",i);
		return 0;
	}
} 