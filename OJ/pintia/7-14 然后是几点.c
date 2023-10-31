#include<stdio.h> 
int main()
{
	int s=0,j=0,h=0,m=0;
	scanf("%d %d",&s,&j);
	h=s/100+j/60;
	m=s%100+j%60;
	if(m>=60)
	h=h+1,m=m%60;
	if(s%100==0&&m<0){
	h=h-1,m=60+m;
	if(m>=60)
	h=h+1,m=m%60;
	}
	s=h*100+m;
	printf("%03d",s);
} 
